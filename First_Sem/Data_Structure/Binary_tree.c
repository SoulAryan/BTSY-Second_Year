#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create()
{
    int x;
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the data (-1 for no node) = ");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }

    newnode->data=x;

    printf("Enter the left child of %d ",x);
    newnode->left=create();

    printf("Enter the right child of %d ",x);
    newnode->right=create();

    return newnode;
}

void Print_Data(struct Node *root)               //Preoder Traversal
{
    if(root==NULL)
    {
        return;  //STOP Condition
    }

    printf("%d  ",root->data);
    Print_Data(root->left);
    Print_Data(root->right);
}
void main()
{
    struct Node *root;
    root=0;
    root=create();
    Print_Data(root);    
}