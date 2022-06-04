#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Node
{
	int data;
	struct Node *next;
}*hashTable[size],*current,*p;
void insertValue(int value) 
 {
	int index=value%size;
	current=(struct Node*)malloc(sizeof(struct Node));
	current->data = value;
	current->next = NULL;
	if(hashTable[index] == NULL)
		hashTable[index] = current;
	else 
	{
		p = hashTable[index];
		while(p->next != NULL) 
		{
	      p = p->next;
		}
	   p->next = current;
	}
 }
 void displayValue() 
 {
	for(int i=0;i<size;i++) 
	{
		p=hashTable[i];
		if(p==NULL)
			printf("Null");
		else 
		{
			while(p!=NULL) 
			{
				printf("%d->",p->data);
				p=p->next;
			}
		}
		printf("\n");
	}
 }
int main()
{
   for(int i=0;i<size-1;i++)
		hashTable[i]=NULL;
	while(1) 
	{
		printf("1.Insert \t 2.Display \t 3.Exit \n Enter your choice:");
		int ch;
		scanf("%d",&ch);
		switch(ch) 
		{
		   case 1: 
			      printf("Enter value");
			      int value;
			      scanf("%d",&value);
			      insertValue(value);
		         break;
		   case 2: 
			      printf("values are");
			      displayValue();
		         break;
		   case 3:
			      exit(0);
	   }
	}
}
