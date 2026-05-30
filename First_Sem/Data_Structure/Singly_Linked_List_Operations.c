//Create a link list(insertion,deletion and traversal)//
/*#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
    
};

int main()
{
    struct Node *current;
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=45;
    head->link=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=56;
    second->link=NULL;
    head->link=second;

    struct Node *third=NULL;
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=34;
    third->link=NULL;
    second->link=third;

    struct Node *fourth=NULL;
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fourth->data=12;
    fourth->link=NULL;
    third->link=fourth;


    struct Node *fifth=NULL;
    fifth=(struct Node*)malloc(sizeof(struct Node));
    fifth->data=89;
    fifth->link=NULL;
    fourth->link=fifth;

    current=head;

    while(current!=NULL)                                       //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->link != NULL) 
        {
            printf(" -> ");

        }
        current = current->link;
    }
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

int main()
{
    struct Node *current;
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=80;
    head->link=NULL;

    struct Node *first=NULL;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=90;
    first->link=NULL;
    

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=100;
    second->link=NULL;
    
    struct Node *third=NULL;
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=110;
    third->link=NULL;

    //Linking of nodes//
    head->link=first;
    first->link=second;
    second->link=third;
    third->link=NULL;

                                                              //Node insertion in the middle//

    struct Node *newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=120;
    newnode->link=NULL;
    second->link=newnode;
    newnode->link=third;

    current=head;
    while(current!=NULL)                                          //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->link != NULL) 
        {
            printf(" -> ");

        }
        current = current->link;
    }
    
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=12;
    head->ptr=NULL;

    struct node *first=NULL;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=24;
    first->ptr=NULL;

    struct node *second=NULL;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=36;
    second->ptr=NULL;

    struct node *fourth=NULL;                              //We delete the third node and assign the memory address of fourth to the second node//
    fourth=(struct node*)malloc(sizeof(struct node));
    fourth->data=60;
    fourth->ptr=NULL;

    //Linking of nodes//
    head->ptr=first;
    first->ptr=second;
    second->ptr=fourth;
    fourth->ptr=NULL;

    struct node *current;
    current=head;

    while(current!=NULL)
    {
        printf("%d",current->data);
        if(current->ptr!=NULL)
        {
            printf(" -> ");
        }
        current=current->ptr;
    }

    return 0;

}*/

/*#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

int main()
{
    struct Node *newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=0;
    newnode->link=NULL;
    

    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->link=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=2;
    second->link=NULL;

    struct Node *third=NULL;
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=3;
    third->link=NULL;

    struct Node *fourth=NULL;
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fourth->data=4;
    fourth->link=NULL;

    //Linking of nodes//
    newnode->link=head;                                   //Node insertion at the beginning//
    head->link=second;
    second->link=third;
    third->link=fourth;
    fourth->link=NULL;

    struct Node *current;
    head=newnode;                                         //head is assigned to newnode//
    current=head;
    while(current!=NULL)
    {
        printf("%d",current->data);
        if(current->link!=NULL)
        {
            printf(" -> ");
        }
        current=current->link;
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=10;
    head->link=NULL;

    struct Node *second=NULL;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=20;
    second->link=NULL;

    struct Node *third=NULL;                                   //Node insertion at the end//
    third=(struct Node*)malloc(sizeof(struct Node));
    third->data=30;
    third->link=NULL;

    //Linking of nodes//
    head->link=second;
    second->link=third;
    third->link=NULL;

    struct Node *current;

    current=head;
    printf("\n");

    while(current!=NULL)                                          //Traversal of the link list//
    {
        printf("%d",current->data);
        if(current->link != NULL) 
        {
            printf(" -> ");

        }
        current = current->link;
    }

     return 0;
}
