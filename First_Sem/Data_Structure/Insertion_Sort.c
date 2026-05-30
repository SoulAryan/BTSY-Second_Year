//Best Case = O(n)
//Average Case = O(n^2)
//Worst Case = O(n^2)

#include <stdio.h>
void Insertion_Sort(int arr[],int n)
{
    int i,j,temp;

    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;     
        }
        arr[j+1]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
}
int main()
{
    int arr[100];
    int n;
    int i;
    
    printf("Enter how many number of elements you want to sort: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element at index %d = ",i);
        scanf("%d",&arr[i]);
    }

    printf("Original Array:\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nSorted Array:\n");

    Insertion_Sort(arr,n);

    return 0;
}

