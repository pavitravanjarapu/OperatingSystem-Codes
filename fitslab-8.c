
#include <stdio.h>

void firstFit(int bSize[], int bCount, int pSize[], int pCount) {
    int alloc[100], i, j;
    for (i = 0; i < pCount; i++) {
        alloc[i] = -1;
        for (j = 0; j < bCount; j++) {
            if (bSize[j] >= pSize[i]) {
                alloc[i] = j;
                bSize[j] -= pSize[i];
                break;
            }
        }
    }

    for (i = 0; i < pCount; i++) {
        printf("Alloc[%d]\n", pSize[i]);
        if (alloc[i] != -1)
            printf("Process %d of size %d is allocated in block %d\n", i, pSize[i], alloc[i]);
        else
            printf("Process %d of size %d is not allocated\n", i, pSize[i]);
    }
}

void bestFit(int bSize[], int bCount, int pSize[], int pCount) {
    int alloc[100], i, j;
    for (i = 0; i < pCount; i++) {
        alloc[i] = -1;
        int bestIdx = -1;
        for (j = 0; j < bCount; j++) {
            if (bSize[j] >= pSize[i]) {
                if (bestIdx == -1 || bSize[j] < bSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            alloc[i] = bestIdx;
            bSize[bestIdx] -= pSize[i];
        }
    }

    printf("\nBest Fit\n");
    for (i = 0; i < pCount; i++) {
        printf("Alloc[%d]\n", pSize[i]);
        if (alloc[i] != -1)
            printf("Process %d of size %d is allocated in block:%d\n", i, pSize[i], alloc[i]);
        else
            printf("Process %d of size %d is not allocated\n", i, pSize[i]);
    }
}

void worstFit(int bSize[], int bCount, int pSize[], int pCount) {
    int alloc[100], i, j;
    for (i = 0; i < pCount; i++) {
        alloc[i] = -1;
        int worstIdx = -1;
        for (j = 0; j < bCount; j++) {
            if (bSize[j] >= pSize[i]) {
                if (worstIdx == -1 || bSize[j] > bSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            alloc[i] = worstIdx;
            bSize[worstIdx] -= pSize[i];
        }
    }

    printf("\nWorst Fit\n");
    for (i = 0; i < pCount; i++) {
        printf("Alloc[%d]\n", pSize[i]);
        if (alloc[i] != -1)
            printf("Process %d of size %d is allocated in block %d\n", i, pSize[i], alloc[i]);
        else
            printf("Process %d of size %d is not allocated\n", i, pSize[i]);
    }
}

int main() {
    int pSize[100], bSize[100], originalBSize[100];
    int pCount, bCount, i, choice;

    printf("Enter the no of process: ");
    scanf("%d", &pCount);

    printf("Enter the no of blocks: ");
    scanf("%d", &bCount);

    printf("Enter the size of each process:\n");
    for (i = 0; i < pCount; i++) {
        printf("Process %d:", i);
        scanf("%d", &pSize[i]);
    }

    printf("Enter the block sizes:\n");
    for (i = 0; i < bCount; i++) {
        printf("Block %d:", i);
        scanf("%d", &bSize[i]);
        originalBSize[i] = bSize[i]; // Save original sizes
    }

    while (1) {
        printf("\n1.First fit 2.Best fit 3.Worst fit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Reset block sizes before each algorithm
        for (i = 0; i < bCount; i++)
            bSize[i] = originalBSize[i];

        switch (choice) {
            case 1:
                firstFit(bSize, bCount, pSize, pCount);
                break;
            case 2:
                bestFit(bSize, bCount, pSize, pCount);
                break;
            case 3:
                worstFit(bSize, bCount, pSize, pCount);
                break;
            default:
                printf("Invalid Choice...!\n");
                return 0;
        }
    }

    return 0;
}

