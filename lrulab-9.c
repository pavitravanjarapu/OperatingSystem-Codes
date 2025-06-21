#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages[100], n, counter = 0;
    int memory[100], time[100];
    int i, j, pageFaults = 0, flag1, flag2;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; ++i) {
        memory[i] = -1;
    }

    printf("\nPage\tMemory\t\tPage Fault\n");

    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; ++j) {
            if (memory[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If not found, add to memory if space is available
        if (flag1 == 0) {
            for (j = 0; j < frames; ++j) {
                if (memory[j] == -1) {
                    counter++;
                    pageFaults++;
                    memory[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If memory is full, replace least recently used page
        if (flag2 == 0) {
            int pos = findLRU(time, frames);
            counter++;
            pageFaults++;
            memory[pos] = pages[i];
            time[pos] = counter;
        }

        // Print output in required format
        printf("%d\t", pages[i]);
        for (j = 0; j < frames; ++j) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }

        printf("\t\t%s\n", flag1 ? "No" : "Yes");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

