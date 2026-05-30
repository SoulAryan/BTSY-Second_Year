#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initTable()
{
    for(int i=0;i<SIZE;i++)
    {
        hashTable[i]=-1;
    }
    
}

int hashFunction(int key)
{
    return key%SIZE;
}

void insert(int key)
{
    int index=hashFunction(key);
    if(hashTable[index]==-1)
    {
        hashTable[index]=key;
    }

    else
    {
         printf("Collision! Cannot insert %d at index %d\n",key,index);
    }
}
void display()
{
    printf("Hast Table:\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d->%d\n",i,hashTable[i]);
    }
    
}
int main() 
{
    initTable();
    insert(15);
    insert(26);
    insert(33);
    
    display();
    
    return 0;
}