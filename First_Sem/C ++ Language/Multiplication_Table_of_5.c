# include <stdio.h>

// Table of 5//

int main()
{
    int a=5;
    
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ", a*j);
        }
        printf("\n");
    }

return 0;
}