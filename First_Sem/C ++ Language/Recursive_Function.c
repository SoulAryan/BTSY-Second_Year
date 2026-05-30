// Multiplication Table of 8 number//
#include <stdio.h>
void Table(int n,int a)
{
    if(a==11)
    {
        return;
    }

    printf("%d x %d = %d",n,a,n*a);
    printf("\n");
    Table(n, a + 1);
}
int main()
{
    int n=8;
    int a=1;
    Table(n,a);

    return 0;
}
