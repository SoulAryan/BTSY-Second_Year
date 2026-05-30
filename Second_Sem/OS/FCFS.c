#include <stdio.h>

void bubble_sort(int n, int p[], int at[], int bt[]) 
{
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = 0; j < n - i - 1; j++) 
        {
            if(at[j] > at[j + 1]) 
            {
                // Swap arrival time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], p[100];
    int wt[100], tat[100], ct[100], rt[100];

    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    bubble_sort(n, p, at, bt);

    // Calculation Logic
    for(int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // The first process starts exactly at its arrival time
            ct[i] = at[i] + bt[i];
        } 
        
        else 
        {
            // If the process arrives AFTER the previous one finished, the CPU was idle
            if (at[i] > ct[i - 1]) 
            {
                ct[i] = at[i] + bt[i];
            } 
            else 
            {
                // Otherwise, it starts right after the previous process finishes
                ct[i] = ct[i - 1] + bt[i];
            }
        }
        
        // Standard formulas for TAT and WT
        tat[i] = ct[i] - at[i];      // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tat[i] - bt[i];      // Waiting Time = Turnaround Time - Burst Time
        wt[i]=rt[i];
    }

   
    printf("\nProcess   Arrival   Burst   Completion   Turnaround   Waiting  Response_Time\n");
    
    for(int i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}