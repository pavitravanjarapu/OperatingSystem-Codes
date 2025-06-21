#include <stdio.h>
#define MAX 10

int main() {
    int n, r;
    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int avail[MAX], work[MAX], finish[MAX];
    int i, j, k, count = 0;

    // Input number of processes and resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource classes: ");
    scanf("%d", &r);

    // Input total instances and available instances
    int total[MAX];
    for (i = 0; i < r; i++) {
        printf("Enter instances of resource class %d: ", i + 1);
        scanf("%d", &total[i]);
        printf("Enter free vectors of resource class %d (resources available): ", i + 1);
        scanf("%d", &avail[i]);
    }

    // Input Allocation Matrix
    printf("Enter the current allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Input Maximum/Request Matrix
    printf("Enter the request matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish and work vectors
    for (i = 0; i < n; i++) finish[i] = 0;
    for (i = 0; i < r; i++) work[i] = avail[i];

    printf("\n");

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == r) {
                    printf("Process %d is satisfied\n", i + 1);
                    for (k = 0; k < r; k++) {
                        work[k] += alloc[i][k];
                        printf("a[%d]=%d\n", k, work[k]);
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) break; // No process could be satisfied in this round
    }

    // Final check
    int safe = 1;
    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            safe = 0;
            break;
        }
    }

    if (safe)
        printf("The system is in a safe state.\n");
    else
        printf("The system is in an unsafe state. Deadlock may occur.\n");

    return 0;
}
