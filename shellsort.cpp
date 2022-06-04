 #include<stdio.h>
int main()
{
	int gap,a[100],temp;
	int i,j,n;
	printf("Enter the size of array elements = ");
	scanf("%d",&n);
	printf("Enter the array elements = ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int gap=n/2;gap>0;gap/=2)
   {
      for (int i=gap;i<n;i+=1)
      {
         int temp=a[i];
			int j;          
         for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
         
			a[j]=a[j-gap];
         a[j]=temp;
        }
   }
	printf("Sorted elements = ");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
