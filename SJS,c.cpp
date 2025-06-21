#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort processes by burst time
void sortByBurstTime(int n, int pid[], int bt[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                swap(&bt[i], &bt[j]);
                swap(&pid[i], &pid[j]);
            }
        }
    }
}

// Calculate waiting time
void findWaitingTime(int n, int bt[], int wt[]) {
    int i;
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Calculate turnaround time
void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Print Gantt Chart
void printGanttChart(int n, int pid[], int bt[]) {
    int i, j, time = 0;

    printf("\nGantt Chart:\n ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", pid[i]);
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }

    printf("\n ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }

    printf("\n0");
    for (i = 0; i < n; i++) {
        time += bt[i];
        printf("%*d", bt[i] * 2, time);
    }
    printf("\n");
}

// Main logic for SJF
void findAvgTime(int n, int bt[]) {
    int wt[n], tat[n], pid[n];
    int total_wt = 0, total_tat = 0;
    int i;

    for (i = 0; i < n; i++) pid[i] = i + 1;

    sortByBurstTime(n, pid, bt);
    findWaitingTime(n, bt, wt);
    findTurnaroundTime(n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    printGanttChart(n, pid, bt);
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n];
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    findAvgTime(n, bt);
    return 0;
}
