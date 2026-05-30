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
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int at[100], bt[100], p[100], rem_bt[100];
    int wt[100], tat[100], ct[100], rt[100];
    
    // Arrays for queue management
    int queue[1000]; 
    int front = 0, rear = 0;
    int visited[100] = {0}; // Tracks if a process has been added to the queue

    for(int i = 0; i < n; i++) 
    {
        p[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Sort initially by Arrival Time
    bubble_sort(n, p, at, bt);
    
    // Keep rem_bt synced with the sorted bt array
    for(int i = 0; i < n; i++) 
    {
        rem_bt[i] = bt[i];
    }

    // Round Robin Calculation Logic
    int current_time = 0;    // Tracks the current time in the simulation
    int completed_count = 0; // Tracks how many processes have finished

    // Initially enqueue any processes that have arrived at time 0
    for(int i = 0; i < n; i++) 
    {
        if(at[i] <= current_time && visited[i] == 0) 
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // We use a while loop to process the queue until all processes complete
    while(completed_count < n) 
    {
        if(front == rear) 
        {
            // If the queue is empty but processes aren't done, the CPU is idle.
            current_time++;
            
            // Check if any new process arrived during idle time
            for(int i = 0; i < n; i++) 
            {
                if(at[i] <= current_time && visited[i] == 0) 
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        } 
        else 
        {
            // Dequeue the next process to execute
            int i = queue[front++]; 

            // Response Time = First time it gets CPU - Arrival Time
            // We know it's the first time if remaining burst time equals original burst time
            if(rem_bt[i] == bt[i]) 
            {
                rt[i] = current_time - at[i]; 
            }

            // Determine how long to execute: either the full quantum or whatever is left
            int execution_time;
            if(rem_bt[i] < time_quantum) 
            {
                execution_time = rem_bt[i];
            } 
            else 
            {
                execution_time = time_quantum;
            }

            // Advance the timeline and reduce remaining burst time
            rem_bt[i] -= execution_time;
            current_time += execution_time;

            // CRITICAL STEP: Check for newly arrived processes while this one was executing
            // Add them to the queue BEFORE we put the currently executing process back in
            for(int j = 0; j < n; j++) 
            {
                if(at[j] <= current_time && visited[j] == 0) 
                {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }

            // Check if the current process finished
            if(rem_bt[i] == 0) 
            {
                // Completion Time = Current Time
                ct[i] = current_time; 
                
                // Turnaround Time = Completion Time - Arrival Time
                tat[i] = ct[i] - at[i]; 
                
                // Waiting Time = Turnaround Time - Burst Time
                wt[i] = tat[i] - bt[i]; 

                completed_count++;
            } 
            else 
            {
                // If it's not finished, re-enqueue it for its next turn
                queue[rear++] = i;
            }
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