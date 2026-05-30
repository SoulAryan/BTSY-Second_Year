//Inorder,Preorder and Postorder Traversal of a Binary Tree
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
};

void Inorder(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }

    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Preorder(struct Node *root)
{
    if(root==NULL)
    {
        return ;
    }

    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void main()
{
    struct Node *root;
    root=0;
    root=create();

    printf("\nInorder Traversal = ");
    Inorder(root);

    printf("\nPreorder Traversal = ");
    Preorder(root);

    printf("\nPostorder Traversal = ");
    Postorder(root);
}