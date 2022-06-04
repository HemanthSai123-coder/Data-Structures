#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
	int data;
	struct Node *next,*prev;
}*head=NULL;
void create(int value)
{
	struct Node *new_node,*ptr;
	new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=value;
	new_node->prev=NULL;
	new_node->next=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->prev=ptr;
	}//else
}//create
void display()
{
	struct Node *ptr;
	if(head==NULL)
	{
		printf("LINKED LIST IS EMPTY\n");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d ->",ptr->data);
			ptr=ptr->next;
		}
	}//else
}//display
void insertAtBegin(int value)
{
	struct Node *new_node,*ptr;
	new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=value;
	new_node->next=head;
	head->prev=new_node;
	head=new_node;	
}//insertAtBegin
void insertAtEnd(int value)
{
	struct Node *new_node,*ptr;
	new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=value;
	new_node->next=NULL;
	if(head==NULL)
	{
	    head=new_node;		
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->prev=ptr;
	}
}//insertAtEnd
void insertAtAnyPos(int value)
{
	 int pos,i;
	 struct Node *new_node,*ptr;
	 new_node=(struct Node*)malloc(sizeof(struct Node));
	 new_node->data=value;
	 //new->next=NULL;//optional
	 printf("Enter any position=");
	 scanf("%d",&pos);
	 ptr=head;
	 if(pos==1)
	 {
	 	new_node->next=head;
	 	head->prev=new_node;
	 	head=new_node;
	 }
	 else
	 {
	 	for(i=1;i<pos-1&&ptr!=NULL;i++)
	 	{
	 		ptr=ptr->next;
		 }
		 if(ptr==NULL)
		 {
		 	printf("WE CAN'T Perform insertion(INVALID POSITION)");
		 }
		 else
		 {
		 	new_node->next=ptr->next;
		 	ptr->prev=new_node;
		 	ptr->next=new_node;
		 	new_node->prev=ptr;
		 }
	 }//else
}//insetAtAnyPos
void deleteAtBegin()
{
	struct Node *ptr;
	if(head==NULL)
	{
		printf("Deletion not possible:\n");
	}
	else
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		printf("Deleted element is: %d\n",ptr->data);
		free(ptr);
	}
}//deleteAtBegin
void deleteAtEnd()
{
	struct Node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("Deletion not possible:\n");	
	}
	else if(head->next==NULL)
	{
		    ptr=head;
			head=NULL;
	}
	else
	{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}//while
			ptr1->next=NULL;
			ptr->prev=NULL;
	}
	printf("Deleted element is: %d\n",ptr->data);
	free(ptr);	
}//deleteAtEnd
void deleteAtAnyPos()
{
	int pos,i;
	struct Node *ptr,*ptr1;
	printf("Enter position to be delete=");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		ptr=head;
		if(pos==1)
		{	
			head=head->next;
			free(ptr);
		}
		else
		{
			for(i=1;i<=pos-1&&ptr!=NULL;i++)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			if(ptr==NULL)
			{
				printf("Deletion not possible\n");
			}
			else
			{
				ptr1->next=ptr->next;
				ptr->next->prev=ptr1;
				free(ptr);
			}	
		}//else	
	}//else
}//function
int main()
{
	int choice,num,n,result,f=0,i;
	do
	{
		printf("\n**LINKEDLIST MENU**\n");
		printf("1.create\n2.display\n");
		printf("3.insertAtBegin\n4.insertAtEnd\n5.insertAtAnyPos\n");
		printf("6.deleteAtBegin\n7.deleteAtEnd\n8.delerteAtAnyPos\n");
		printf("9.exit\n");
		printf("Enter your choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter noof nodes to be created:");
	            scanf("%d",&n);
	            for(i=1;i<=n;i++)
				{
				    printf("Enter number=");
				    scanf("%d",&num);
				    create(num);
			    }
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter number=");
				scanf("%d",&num);
				insertAtBegin(num);
				break;
			case 4:
				printf("Enter number=");
				scanf("%d",&num);
				insertAtEnd(num);
				break;
			case 5:
				printf("Enter number=");
				scanf("%d",&num);
				insertAtAnyPos(num);
				break;
			case 6:
				deleteAtBegin();
				break;
			case 7:
				deleteAtEnd();
				break;
			case 8:
				deleteAtAnyPos();
				break;
			case 9:
				break;
		}
	}while(choice!=9);
}
