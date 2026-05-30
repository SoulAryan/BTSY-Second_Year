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

    // 1. Input
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter page reference string:\n");
    for(int i = 0; i < num_pages; i++) {
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

        // Step B: Page Fault (Miss) -> Apply Optimal Logic
        if(!is_hit) 
        {
            int replace_index = -1;
            int farthest_use = -1;

            // Examine each frame to see which one to replace
            for(int j = 0; j < num_frames; j++) 
            {
                int future_use = -1;

                // Look ahead to find when this frame's page is next used
                for(int k = i + 1; k < num_pages; k++) 
                {
                    if(frames[j] == pages[k]) 
                    {
                        future_use = k;
                        break;
                    }
                }

                // If a frame is empty (-1) OR its page is never used again in the future
                if(future_use == -1) 
                {
                    replace_index = j;
                    break; // Replace this one immediately
                }

                // Keep track of the page that is used farthest in the future
                if(future_use > farthest_use) 
                {
                    farthest_use = future_use;
                    replace_index = j;
                }
            }

            // Replace the chosen frame with the new page
            frames[replace_index] = pages[i];
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

    // Calculate the ratios by casting to float for decimal division
    float fault_ratio = (float)faults / num_pages;
    float hit_ratio = (float)(num_pages - faults) / num_pages;
    
    // Print the ratios to 2 decimal places
    printf("Fault Ratio = %.2f\n", fault_ratio);
    printf("Hit Ratio = %.2f\n\n", hit_ratio);

    return 0;
}