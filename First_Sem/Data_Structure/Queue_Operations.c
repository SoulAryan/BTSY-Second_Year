/////////////////////////////////////////////QUEUE////////////////////////////////////////
//////QUEUE DEMONSTARTION : FIFO (First In First Out)  OR   LILO (Last In Last Out)////////////////////////////////////
/*#include <stdio.h>
int main()
{
    int queue[6];

    for(int i=0;i<6;i++)
    {
        printf("Enter the value to the queue[%d]",i);
        scanf("%d",&queue[i]); 
    }

    for(int i=0;i<6;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");

    return 0;
}*/

//////////////////////////////QUEUE OPERATIONS//////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int choice_number)
{
    if(rear==SIZE-1)
    {
        printf("Queue Overflow.Cannot insert the value in the queue");
    }

    else
    {
        if(front==-1)
        {
            front=0;
        }

        queue[++rear]=choice_number;
        printf("%d is inserted in the queue",choice_number);
    }

}

void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Overflow Error:Queue is empty");
    } 

    else
    {
        printf("%d is deleted from the queue",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The elements in the queue are:\n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice_number, choice;

    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &choice_number);
                enqueue(choice_number);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
