#include <stdio.h>
#define size 10
struct hash
{
   int hkey,key;
}ht[size];
void insert()
{
    int ele,index;
    printf("eneter the key");
    scanf("%d",&ele);
    index=ele%size;
    if(ht[index].key==-1)
    ht[index].key=ele;
    else
    {
        for(int j=1;j<size;j++)
        {
            int t=(index+j)%size;
            if(ht[t].key==-1)
            {
            ht[t].key=ele;
            break;
            }
        }
    }
}
void search()
{
	int ele,index,j,flag=0;
	printf("enter the key value to search\n");
	scanf("%d",&ele);
	index=ele%size;
	if(ht[index].key==ele)
	printf("key is found at index %d\n",index);
	    else
		{
		for(int j=1;j<size;j++)
        {
            int t=(index+j)%size;
            if(ht[t].key==ele)
            {flag=1;
            break;
            }
          }
      }
if(flag==1)
printf("key value found at index %d=\n",j);
else
printf("key not found\n");
}

void initially()
{
    int i;
    for(i=0;i<size;i++)
    {
        ht[i].key=-1;
        ht[i].hkey=i;
    }
}
void display()
{
    for(int i=0;i<size;i++)
    printf("hash_table[%d]=%d\n",ht[i].hkey,ht[i].key);
    }
int main() {
   
    initially();
    insert();
    insert();
    insert();
    insert();
    display();
    return 0;
}
