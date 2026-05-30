#include <stdio.h>
#include <stdbool.h>

// Define maximum sizes to avoid Variable Length Array (VLA) compiler warnings
#define MAX_PAGES 100
#define MAX_FRAMES 50

int main() {
    int num_pages, num_frames;
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int faults = 0;
    
    // Pointer to track the oldest page for FIFO replacement
    int insert_index = 0; 

    // 1. Input
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter page reference string:\n");
    for(int i = 0; i < num_pages; i++) 
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    // 2. Initialize frames to -1 (indicating an empty frame)
    for(int i = 0; i < num_frames; i++) 
    {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tStatus\n");
    printf("----------------------------------\n");

    // 3. Process each page in the reference string
    for(int i = 0; i < num_pages; i++) 
    {
        bool is_hit = false;

        // Step A: Check for a Page Hit
        for(int j = 0; j < num_frames; j++) 
        {
            if(frames[j] == pages[i]) 
            {
                is_hit = true;
                break;
            }
        }

        // Step B: Page Fault (Miss) -> Apply FIFO Logic
        if(!is_hit) 
        {
            // Replace the oldest page at the current insert_index
            frames[insert_index] = pages[i];
            
            // Move the pointer to the next oldest page (circular queue logic)
            insert_index = (insert_index + 1) % num_frames;
            
            faults++;
        }

        // Step C: Print the current state
        printf("%d\t", pages[i]);
        for(int j = 0; j < num_frames; j++) 
        {
            if(frames[j] != -1) 
            {
                printf("%d ", frames[j]);
            } 
            else 
            {
                printf("- ");
            }
        }
        
        // Print Miss/Hit status for easier debugging
        if (!is_hit) 
        {
            printf("\t\t[Fault]");
        } 
        else 
        {
            printf("\t\t[Hit]");
        }
        printf("\n");
    }

    printf("----------------------------------\n");
    printf("Total Page Faults = %d\n\n", faults);


    // We use (float) to prevent integer division which would just give us 0
    float fault_ratio = (float)faults / num_pages;
    float hit_ratio = (float)(num_pages - faults) / num_pages;
    
    // %.2f prints the float to 2 decimal places
    printf("Fault Ratio = %.2f\n", fault_ratio);
    printf("Hit Ratio = %.2f\n\n", hit_ratio);
    
    return 0;
}