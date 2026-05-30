/*                                          //For Singly Linked List//
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
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->link=NULL;

    struct Node *second=NULL;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=20;
    second->link=NULL;

    struct Node *third=NULL;
    third=(struct Node *)malloc(sizeof(struct Node));
    third->data=30;
    third->link=NULL;

    struct Node *fourth=NULL;
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fourth->data=40;
    fourth->link=NULL;

    struct Node *fifth=NULL;
    fifth=(struct Node *)malloc(sizeof(struct Node));
    fifth->data=50;
    fifth->link=NULL;

    //Linking the nodes
    head->link=second;
    second->link=third;
    third->link=fourth;
    fourth->link=fifth;
    fifth->link=head;                 //Making the linked list circular

    struct Node *current;             //Traversing the circular linked list
    current=head;
    do
    {
        printf("%d ",current->data);
        current=current->link;
    } while (current!=head);

    printf("%d",head->data);          //To show the circular linked list//

    return 0;
}*/

                                                 //For Doubly Linked List//
/*#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=NULL;
    head->prev=NULL;

    struct Node *second=NULL;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=20;
    second->next=NULL;
    second->prev=head;

    struct Node *third=NULL;
    third=(struct Node *)malloc(sizeof(struct Node));
    third->data=30;
    third->next=NULL;
    third->prev=second;

    struct Node *fourth=NULL;
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fourth->data=40;
    fourth->next=NULL;
    fourth->prev=third;

    struct Node *fifth=NULL;
    fifth=(struct Node *)malloc(sizeof(struct Node));
    fifth->data=50;
    fifth->next=NULL;
    fifth->prev=fourth;

    //Linking the nodes
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    fourth->next=fifth;
    fifth->prev=fourth;
    fifth->next=head;                  //Making the linked list circular

    struct Node *current;             //Traversing the circular linked list//
    current=head;
    do
    {
        printf("%d ",current->data);
        current=current->next;
        
    } while (current!=head);

    printf("%d",head->data);          //To show the circular linked list//

    return 0;
}*/

/*//Insertion and deletion for singly circular linked list//
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
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->link=NULL;

    struct Node *third=NULL;
    third=(struct Node *)malloc(sizeof(struct Node));                   //We have removed the second node//
    third->data=30;                                                     //head node is linked to third node//
    third->link=NULL;

    struct Node *fourth=NULL;
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fourth->data=40;
    fourth->link=NULL;

    struct Node *fifth=NULL;                                  //Fifth node in between third and fourth//
    fifth=(struct Node *)malloc(sizeof(struct Node));
    fifth->data=50;
    fifth->link=NULL;



    //Linking the nodes
    head->link=third;
    fourth->link=head;
    third->link=fifth;                       //Linking the third node to fifth node//
    fifth->link=fourth;                      //Linking the fifth node to fourth node//
    
    struct Node *current;             //Traversing the circular linked list
    current=head;
    do
    {
        printf("%d ",current->data);
        current=current->link;
    } while (current!=head);

    printf("%d",head->data);          //To show the circular linked list//

    return 0;
}*/

//Insertion and deletion for doubly circular linked list//
/*#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *head=NULL;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=NULL;
    head->prev=NULL;

    struct Node *third=NULL;
    third=(struct Node *)malloc(sizeof(struct Node));                   //We have removed the second node//
    third->data=30;                                                     //head node is linked to third node//
    third->next=NULL;
    third->prev=head;

    struct Node *fourth=NULL;
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fourth->data=40;
    fourth->next=NULL;
    fourth->prev=third;

    struct Node *fifth=NULL;                                  //Fifth node in between third and fourth//
    fifth=(struct Node *)malloc(sizeof(struct Node));
    fifth->data=50;
    fifth->next=NULL;
    fifth->prev=third;

    //Linking the nodes
    head->next=third;
    third->prev=head;
    third->next=fifth;                       //Linking the third node to fifth node//
    fifth->prev=third;
    fifth->next=fourth;                      //Linking the fifth node to fourth node//
    fourth->prev=fifth;
    fourth->next=head;
    head->prev=fourth;

    struct Node *current;             //Traversing the circular linked list//
    current=head;
    do
    {
        printf("%d ",current->data);
        current=current->next;


    }while(current!=head);

    printf("%d",head->data);          //To show the circular linked list//

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
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->link=NULL;

    struct Node *second=NULL;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=20;
    second->link=NULL;

    struct Node *third=NULL;
    third=(struct Node *)malloc(sizeof(struct Node));
    third->data=30;
    third->link=NULL;

    //Linking the nodes
    head->link=second;
    second->link=third;
    third->link=head;      //Making the linked list circular
    
    struct Node *current;  //Traversing the circular linked list
    current=head;
    printf("\n");
    do
    {
        printf("%d ",current->data);
        current=current->link; 
    } while (current!=head);
    
    printf("%d",head->data);  //To show the circular linked list//

    return 0;
}