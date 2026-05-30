#include <stdio.h>
int main()
{
    int marks;

    printf("Please enter your marks=");
    scanf("%d",&marks);

    if(marks>=101)
    {
        printf("Please enter your marks in between 0 to 100");
    }

    else if(marks>75)
    {
        printf("Congratulations,you are in DISTINCTION");
    }

    else if(marks>=60)
    {
        printf("Congratulations,you are in FIRST CLASS");
    }

    else if(marks>=50)
    {
        printf("Congratulations,you are PASS");
    }

    else if(marks<35)
    {
        printf("Sorry,you are FAIL");
    }

    return 0;
}