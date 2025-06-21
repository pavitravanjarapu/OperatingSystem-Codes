#include <stdio.h>

int findLFU(int freq[], int frames) {
    int min = freq[0], pos = 0, i;
    for (i = 1; i < frames; i++) {
        if (freq[i] < min) {
            min = freq[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, frames;
    int pages[100], memory[100], freq[100];
    int i, j, k, pageFaults = 0, found, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        memory[i] = -1;
        freq[i] = 0;
    }

    printf("\nPage\tMemory\t\tPage Fault\n");

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // If page not found
        if (!found) {
            pageFaults++;
            for (j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    memory[j] = pages[i];
                    freq[j] = 1;
                    found = 1;
                    break;
                }
            }
        }

        // If memory full, replace LFU
        if (!found) {
            pos = findLFU(freq, frames);
            memory[pos] = pages[i];
            freq[pos] = 1;
        }

        // Print memory state
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

