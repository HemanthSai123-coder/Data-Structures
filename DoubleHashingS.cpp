#include <stdio.h>
#define size 10
#define prime 7
struct hash
{
    int hkey,key;
}ht[size];
void insert()
{
    int ele,h1,h2,index,i;
    printf("eneter the key");
    scanf("%d",&ele);
    h1=ele%size;
    h2=prime-(ele%prime);
   
     for( i=0;i<size;i++)
 { index=(h1+i*h2)%size;
    if(ht[index].key == -1)
    {
        ht[index].key=ele;
        break;
    }
   
        }
        if(i==size)
        printf("element can't be inserted");
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
void search()
{

    int ele,h1,h2,index,i;
    printf("eneter the key");
    scanf("%d",&ele);
    h1=ele%size;
    h2=prime-(ele%prime);
    for( i=0;i<size;i++)
 {
     index=(h1+i*h2)%size;
    if(ht[index].key == ele)
    {
        printf("value is found at index %d",index);
      break;
    }
   
        }
        if(i==size)
        printf("\n value is not found\n");
    }
   
   

void display()
{int i;
    for(i=0;i<size;i++)
    printf("hash_table[%d]=%d\n",ht[i].hkey,ht[i].key);
    }
int main() {
   
    initially();
    insert();
    insert();
    insert();
    insert();
    display();
    search();
    return 0;
}
