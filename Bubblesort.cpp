#include<stdio.h>
int bubblesort(int);
int bubblesort(int n)
{
	int a[100],temp;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("The Array elements are =");
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
		   	a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int main()
{
	int n;
	printf("Enter No.of array elements=");
	scanf("%d",&n);
	bubblesort(n);
	return 0;
}
