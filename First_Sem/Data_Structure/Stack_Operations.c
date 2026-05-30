/////////////////////////////////////////////STACK//////////////////////////////////////
// Stack demonstration: FILO (First In Last Out) OR  LIFO (Last In First Out)
/*#include <stdio.h>
int main()
{
    int stack[6];
    int top = -1;
    int i;

   
    for (i = 0; i < 6; i++)
    {
        printf("Enter the value of stack[%d]: ", i);
        scanf("%d", &stack[++top]); 
    }
    for (i = top; i >= 0; i--)
    {
        printf("Value of stack[%d] = %d\n", i, stack[i]);
    }

    return 0;
}*/

///////////////////////////STACK OPERATIONS////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int choice_number)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow, Cannot push the value in the stack\n");
    }
    else
    {
        stack[++top] = choice_number;
        printf("The value %d is pushed in the stack\n", choice_number);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow, Cannot pop the value from the stack\n");
    }
    else
    {
        printf("The value %d is popped out from the stack\n", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty. No value is in the stack\n");
    }
    else
    {
        printf("The value to peek is %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("There are no elements in the stack\n");
    }
    else
    {
        printf("The elements of the stack are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice_number, choice;
    do
    {
        printf("\n--- Stack Menu ---\n");
        printf("1 > Push Operation\n");
        printf("2 > Pop Operation\n");
        printf("3 > Peek Operation\n");
        printf("4 > Display Stack\n");
        printf("5 > Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed in the stack: ");
            scanf("%d", &choice_number);
            push(choice_number);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}