#include<stdio.h>   
int partition(int a[],int first,int last)  
{  
   int pivot=a[last];   
   int i=(first-1);  
   for(int j=first;j<=last-1;j++)  
   {  
      if(a[j]<pivot)  
      {  
         i++;   
         int t=a[i];  
         a[i]=a[j];  
         a[j]=t;  
      }  
   }  
   int t=a[i+1];  
   a[i+1]=a[last];  
   a[last]=t;  
   return(i+1);  
}   
void quick(int a[],int first,int last) 
{  
   if(first<last)  
   {  
      int p = partition(a,first,last); 
      quick(a,first,p-1);  
      quick(a,p+1,last);  
   }  
}    
 /*void printArr(int a[],int n)  
{  
   int i;  
   for(i=0;i<n;i++)  
   printf("%d ",a[i]);  
} */
int main()
{
	int n,a[100],i;
	printf("Enter the size of the array elements = ");
	scanf("%d",&n);
	printf("Enter the array elements = ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//printArr(a,n);  
   quick(a,0,n-1);
   printf("Sorted elements = ");
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
   return 0;
}
