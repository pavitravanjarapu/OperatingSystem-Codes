#include <stdio.h>

int main() {
    int frames, pages[100], n, i, j, k, pageFaults = 0;
    int memory[100], front = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize memory with -1 (indicating empty)
    for (i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    printf("\nPage\tMemory\t\tPage Fault\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found, replace using FIFO
        if (!found) {
            memory[front] = pages[i];
            front = (front + 1) % frames;
            pageFaults++;
        }

        // Print current memory state
        printf("%d\t", pages[i]);
        for (k = 0; k < frames; k++) {
            if (memory[k] != -1)
                printf("%d ", memory[k]);
            else
                printf("- ");
        }

        printf("\t\t%s\n", found ? "No" : "Yes");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

