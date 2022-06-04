#include<stdio.h>
void mergesort(int a[],int i, int j);
void merge(int a[],int f1,int l1,int f2,int l2);

void mergesort(int a[],int i, int j)
{
	int mid, k;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j); 
		merge(a,i,mid,mid+1,j);
		/*for(k=i;k<=j;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");*/
	}
}
void merge(int a[],int f1,int l1,int f2,int l2)
{
	int b[50],i,j,k;
	i=f1;
	j=f2;
	k=0;
	while(i<=l1&&j<=l2)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
		   b[k]=a[j];
			j++;
			k++;
		}	
	}
	while(i<=l1)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=l2)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	i=f1;
	j=0;
	while(i<=l2)
	{
		a[i]=b[j];
		i++;
		j++;
	}
}
int main()
{
	int a[50],i,n;
	printf("Enter the size of array elements = ");
	scanf("%d",&n);
	printf("Enter the array elements = ");
	for(i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("Soretd elements = ");
	for(i=0;i<n;i++)
	{
	  printf("%d ",a[i]);
	}
	return 0;
}
