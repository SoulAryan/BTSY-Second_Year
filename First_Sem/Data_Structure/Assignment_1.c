//Normal pointer kitna size store karta hai//
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));

    head->data=56;
    head->link=NULL;

    printf("Data=%d",head->data);
    printf("\nSize of pointer=%u",sizeof(head));
    printf("\nMemory Address of head=%p",head);

    return 0;
}

