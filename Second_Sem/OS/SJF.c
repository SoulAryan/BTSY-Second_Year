#include <stdio.h>
void bubble_sort(int n, int p[], int at[], int bt[]) 
{
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = 0; j < n - i - 1; j++) 
        {
            if(at[j] > at[j + 1] || (at[j] == at[j+1] && bt[j] > bt[j+1])) 
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

int main() 
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], p[100];
    int wt[100], tat[100], ct[100], rt[100];
    int is_completed[100] = {0}; // New array to track finished processes

    for(int i = 0; i < n; i++) 
    {
        p[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort initially by Arrival Time
    bubble_sort(n, p, at, bt);

    // SJF Calculation Logic
    int current_time = 0;     // Tracks the current time in the simulation
    int completed_count = 0;       // how many processes have completed so far

    // We use a while loop because we aren't going in strict array order anymore
    while(completed_count < n) 
    {
        int shortest_index = -1;
        int min_bt = 99999; // Arbitrarily high starting number

        // Scan all processes to find the shortest one that has already arrived
        for(int i = 0; i < n; i++) 
        {
            if(at[i] <= current_time && is_completed[i] == 0) 
            {
                if(bt[i] < min_bt) 
                {
                    min_bt = bt[i];
                    shortest_index = i;
                }
            }
        }

        if(shortest_index != -1) 
        {
            // We found a process to execute
            int i = shortest_index;

            // Response Time = First time it gets CPU - Arrival Time
            rt[i] = current_time - at[i]; 
            
            // Completion Time = Current Time + Burst Time
            ct[i] = current_time + bt[i]; 
            
            // Turnaround Time = Completion Time - Arrival Time
            tat[i] = ct[i] - at[i]; 
            
            // Waiting Time = Turnaround Time - Burst Time
            wt[i] = tat[i] - bt[i]; 

            // Advance the timeline and mark as complete
            current_time = ct[i]; 
            is_completed[i] = 1;
            completed_count++;
        } 
        else 
        {
            // If no processes have arrived yet, the CPU sits idle. Advance time.
            current_time++;
        }
    }

    // Print Results
    printf("\nProcessID \t Arrival \t Burst \t Completion \t Turnaround \t Waiting \t Response_Time\n");
    
    // Note: They print in the order they were initially sorted (by arrival time)
    for(int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t %d\t\t %d\t\t %d\t\t %d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}