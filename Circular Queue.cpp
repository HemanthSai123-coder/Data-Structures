//Circular Queue---------------Implementation------------------

#include<stdio.h>
#include<stdlib.h>
# define size 10
int cqueue[size];
int front = -1;
int rear = -1;

void cEnqueue(int x)
{
   if(front==((rear+1)%size))
   printf("queue is full\n");
   else if(front==-1 && rear==-1)
   {
      front=rear=0;
      cqueue[rear]=x;
      printf("%d is inserted successfully\n",x);
   }
   else
	{
      rear=(rear+1)%size;
      cqueue[rear]=x;
      printf("%d is inserted successfully\n",x);
   }
}
void cDequeue()
{
   if(front==-1 && rear==-1)
   printf("Circular Queue is empty\n");
   else if(front==rear)
   {
      printf("%d is deleted successfully\n",cqueue[front]);
      front=rear=-1;
   }
   else
	{
      printf("%d is deleted successfully\n",cqueue[front]);
      front=(front+1)%size;
   }
}
void display()
{
   int i;
   if(front==-1 && rear==-1)
   printf("Circular Queue is empty\n");
   else
	{
      for(i=front;i!=rear;i=(i+1)%size){
      printf("%d ",cqueue[i]);
      }
      printf("%d",cqueue[i]);
        
   }
   printf("\n");
}

int main()
{
   int choice,x;
   do
   {
      printf("**CIRCULAR QUEUE OPERATIONS**\n");
      printf("1.Enqueue\n");
      printf("2.Dequeue\n");
      printf("3.Display\n");
      printf("4.Quit\n");
      printf("\n Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1 : printf("\nEnter the element to insert in Circular Queue: ");
                  scanf("%d", &x);
                  cEnqueue(x);
                  break;
         case 2 : cDequeue();
                  break;
         case 3:  display();
                  break;
         case 4:  exit(0);
         default: printf("Wrong choice!!!\n");
      }
   }while(1);
   return 0;
}
