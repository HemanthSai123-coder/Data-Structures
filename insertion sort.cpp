#include<stdio.h>
int main()
{
   int n,a[100],temp;
   int i,j;
   printf("Enter the size of the array elements : "); //size of array
   scanf("%d",&n);
   printf("Enter the array elements : "); // array elements
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   for(i=1;i<n;i++) // n-1 iterations
   {
      temp=a[i];
      for(j=i;j>0&&temp<a[j-1];j--) //comparing with previous element
      {
         a[j]=a[j-1]; // shifting the elements 
      }
      a[j]=temp; // inserting the element at desired location
   }
   printf("Sorted elements = ");
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
   return 0;
}
