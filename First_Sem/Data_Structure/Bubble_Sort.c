//Best Case = O(n)
//Average Case = O(n^2)
//Worst Case = O(n^2)

#include <stdio.h>
void Bubble_Sort(int arr[],int n)
{
    int i,j,temp,flag;

    for(i=0;i<n-1;i++)
    {
        flag=0;

        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}    
int main()
{
    int arr[100];
    int n;
    int i,j;

    printf("\nEnter how many elements you want to enter=");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element at index %d = ",i);
        scanf("%d",&arr[i]);
    }

    printf("Original Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nSorted Array\n");
    Bubble_Sort(arr,n);

    return 0;
}