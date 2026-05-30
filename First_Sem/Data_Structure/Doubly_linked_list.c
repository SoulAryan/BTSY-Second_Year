///////////////////////////Doubly linked list Operations(insertion,deletion and traversal)///////////////////////////
/*#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->prev=NULL;
    head->next=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=20;    
    second->prev=NULL;
    second->next=NULL;

    struct Node *third=NULL;                                   
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=30;
    third->prev=NULL;
    third->next=NULL;

    struct Node *fourth=NULL;                                   
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fourth->data=40;
    fourth->prev=NULL;
    fourth->next=NULL;

    struct Node *fifth=NULL;                                   //Node insertion in the middle between 2 and 3//  
    fifth=(struct Node*)malloc(sizeof(struct Node));
    fifth->data=50;
    fifth->prev=NULL;
    fifth->next=NULL;

    //Linking of nodes//
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    fourth->next=NULL;
    
    second->next=fifth;                                         //Important steps//
    fifth->prev=second;
    fifth->next=third;
    third->prev=fifth;
               


    struct Node *current;
    current=head;

    while(current!=NULL)                                          //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->next != NULL) 
        {
            printf(" <-> ");

        }
        current = current->next;
    }

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->prev=NULL;
    head->next=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=20;    
    second->prev=NULL;
    second->next=NULL;


    struct Node *fourth=NULL;                                   
    fourth=(struct Node*)malloc(sizeof(struct Node));           //We have deleted the third node and assign the memory address of fourth to second//
    fourth->data=40;
    fourth->prev=NULL;
    fourth->next=NULL;

    //Linking of nodes//
    head->next=second;
    second->prev=head;
    second->next=fourth;
    fourth->prev=second;
    fourth->next=NULL;

    struct Node *current;
    current=head;

    while(current!=NULL)                                          //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->next != NULL) 
        {
            printf(" <-> ");

        }
        current = current->next;
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->prev=NULL;
    head->next=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=20;    
    second->prev=NULL;
    second->next=NULL;

    struct Node *third=NULL;                                   
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=30;
    third->prev=NULL;
    third->next=NULL;

    //Linking of nodes//
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;

    struct Node *current;
    current=head;

    printf("\n");

    while(current!=NULL)       //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->next != NULL) 
        {
            printf(" <-> ");

        }
        current = current->next;
    }

    return 0;
}