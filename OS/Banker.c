#include <stdio.h>
#include <stdlib.h>

#define MAX_PROC 10
#define MAX_RES 10

// Function to check if the current system state is safe
int isSafeState(int n, int m, int alloc[][MAX_RES], int need[][MAX_RES], int avail[], int safeSeq[]) 
{
    int work[MAX_RES];
    int finish[MAX_PROC] = {0}; // 0 represents false/unfinished
    int count = 0;

    // Step 1: Initialize Work = Available
    for (int i = 0; i < m; i++) 
    {
        work[i] = avail[i];
    }

    // Step 2: Find a process that can finish
    while (count < n) 
    {
        int found = 0; // 0 represents false
        
        for (int p = 0; p < n; p++) 
        {
            if (!finish[p]) 
            {
                int j;
                // Check if Need <= Work for all resources
                for (j = 0; j < m; j++) 
                {
                    if (need[p][j] > work[j]) 
                    {
                        break; 
                    }
                }

                // If all resources needed by process 'p' can be satisfied
                if (j == m) 
                {
                    for (int k = 0; k < m; k++) 
                    {
                        work[k] += alloc[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = 1; // 1 represents true/finished
                    found = 1;     // 1 represents true
                }
            }
        }

        // If no process was found in this pass, the system is deadlocked/unsafe
        if (!found) 
        {
            return 0; // 0 represents false
        }
    }
    return 1; // 1 represents true (All processes finished safely)
}

int main() 
{
    int n, m, i, j;
    
    // Fixed-size arrays prevent compilation issues on strict compilers
    int alloc[MAX_PROC][MAX_RES], max[MAX_PROC][MAX_RES], need[MAX_PROC][MAX_RES];
    int total[MAX_RES], avail[MAX_RES];
    int safeSeq[MAX_PROC];

    printf("Enter number of processes (max %d): ", MAX_PROC);
    scanf("%d", &n);

    printf("Enter number of resources (max %d): ", MAX_RES);
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }        

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }        

    printf("\nEnter Total Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &total[i]);
    }    

    // -------- Calculate Available and Need --------
    for(i = 0; i < m; i++) 
    {
        int sum = 0;
        for(j = 0; j < n; j++) 
        {
            sum += alloc[j][i];
        }
        avail[i] = total[i] - sum;
    }

    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < m; j++) 
        {
            need[i][j] = max[i][j] - alloc[i][j];
            
            // Input Validation: Max should never be less than Allocation
            if (need[i][j] < 0) 
            {
                printf("\nError: Process P%d's allocation exceeds its maximum need for resource R%d.\n", i, j);
                return 1; 
            }
        }
    }

    // -------- Print Formatted Output Table --------
    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);
        for(j = 0; j < m; j++) 
        {
            printf("%d ", alloc[i][j]);
        }    
        printf("\t\t");
        for(j = 0; j < m; j++)
        {
            printf("%d ", max[i][j]);
        }    
        printf("\t\t");
        for(j = 0; j < m; j++) 
        {
            printf("%d ", need[i][j]);
        }    
        printf("\n");
    }

    printf("\nInitial Available: ");
    for(i = 0; i < m; i++) 
    {
    printf("%d ", avail[i]);
    }
    printf("\n");

    // -------- Execute Safety Algorithm --------
    if (isSafeState(n, m, alloc, need, avail, safeSeq)) 
    {
        printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
        for(i = 0; i < n; i++) 
        {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    } 
    else 
    {
        printf("\nSystem is NOT in a safe state (Deadlock potential detected).\n");
    }

    return 0;
}