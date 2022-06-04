#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}s;
s *head,*tail,*p,*q,*r,*k; 
void Create()
{
	int n,value,i;
	printf("Enter noof nodes to be created:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=(s*)malloc(sizeof(s));
		printf("Enter the value\n");
		scanf("%d",&value);
		p->data=value;
		p->next=NULL;
		if(i==1)
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
			tail->next=head;
		}
	}
}
void InsertAtBegin()
{
	int value;
	q=(s*)malloc(sizeof(s));
	printf("Enter the value\n");
	scanf("%d",&value);
	q->data=value;
	q->next=head;
	head=q;
	tail->next=head;
}
void InsertAtEnd()
{
	int value;
	r=(s*)malloc(sizeof(s));
	printf("Enter the value\n");
	scanf("%d",&value);
	r->data=value;
	r->next=NULL;
	tail->next=r;
	tail=r;
	tail->next=head;
}
void InsertAtPosition()
{
	int value,pos,i=1;
	q=(s*)malloc(sizeof(s));
	printf("Enter the value and position \n");
	scanf("%d %d",&value,&pos);
	p=head;
	q->data=value;
	while(i<pos)
	{
		r=p;
		p=p->next;
		i++;
	}
	r->next=q;
	q->next=p->next;
}
void DeleteAtBegin()
{
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
	    p=head;
		head=head->next;
		tail->next=head;
		free(p);
	}	
}
void DeleteAtEnd()
{
	
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		p=head;
		while(p->next!=head)
		{
			k=p;
			p=p->next;
		}
		tail=k;
		tail->next=NULL;
		tail->next=head;
		free(p);
	}
}
void DeleteAtAnyPosition()
{
	int i=1,pos;
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
	    printf("Enter position");
	scanf("%d",&pos);
	p=head;
	while(i<pos)
	{
		k=p;
		p=p->next;
		i++;
	}
	k->next=p->next;
	free(p);
}
}
void Display()
{
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		printf("%d",head->data);
		p=head->next;
		while(p!=head)
		{
			printf("->%d",p->data);
			p=p->next;
		}
	}
}
int main()
{
	int choice;
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
				Create();
				break;
			case 2:
				Display();
				break;
			case 3:
				InsertAtBegin();
				break;
			case 4:
				InsertAtEnd();
				break;
			case 5:
				InsertAtPosition();
				break;
			case 6:
				DeleteAtBegin();
				break;
			case 7:
				DeleteAtEnd();
				break;
			case 8:
				DeleteAtAnyPosition();
				break;
			case 9:
				break;
		}
	}while(choice!=9);
}
