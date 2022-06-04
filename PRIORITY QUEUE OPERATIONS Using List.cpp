// PRIORITY QUEUE OPERATION USING LIST

#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   int priority;
   struct Node *next;
}*head=NULL,*current,*p,*q;
void pEnqueue(int data,int priority)
{
   current= (struct Node*)malloc(sizeof(struct Node));
   current->data = data;
   current->priority=priority;
   current->next=NULL;
   if(head == NULL)
   {
      head=current;
      printf("Insertion is successfull\n");
   }
   else if(current->priority < head->priority)
   {
      current->next=head;
      head=current;
      printf("Insertion is successfull\n");
   }
   else
   {
      p=head;
      q=head;
      while(p!=NULL && (p->priority <= current->priority))
      {
         q=p;
         p=p->next;
      }
      current->next=p;
      q->next=current;
      printf("Insertion is successfull\n");
   }
}
void pDequeue()
{
   if(head == NULL)
   {
      printf("Cannot perform Deletion\n");
   }
   else
   {
      p=head;
      head=head->next;
      free(p);
      printf("Deletion is successfull\n");
   }
}
void display()
{
   if(head==NULL)
   {
      printf("Priority Queue is empty,Cannot print data\n");
   }
   else
   {
      p=head;
      while(p!=NULL)
      {
         printf("%d-%d->  ",p->data,p->priority);
         p=p->next;
      }
   }
   printf("\n");
}
int main()
{
   int choice,x,p;
   do
   {
      printf("\n\n*PRIORITY QUEUE OPERATIONS*\n");
      printf("1.Enqueue\n");
      printf("2.Dequeue\n");
      printf("3.Display\n");
      printf("4.Quit\n");
      printf("\n Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
		   case 1 : 
			printf("\nEnter the element and its priority:");
         scanf("%d%d", &x,&p);
         pEnqueue(x,p);
         break;
         
         case 2 : 
			pDequeue();
         break;
         
			case 3:  
			display();
         break;
         
			case 4:
			exit(0);
         
			default: 
			printf("Wrong choice!!!\n");
      }
   }while(1);
   return 0;
}
