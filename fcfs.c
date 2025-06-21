#include <stdio.h>

// Function to find waiting time
void findWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // First process has 0 waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to find turnaround time
void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to print Gantt Chart
void printGanttChart(int n, int bt[]) {
    printf("\nGantt Chart:\n");

    // Top bar	1
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // Process names
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", i + 1);
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }

    // Bottom bar
    printf("\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }

    // Time labels
    printf("\n0");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += bt[i];
        printf("%*d", bt[i] * 2, time);
    }
    printf("\n");
}

// Function to calculate average times and display all
void findAvgTime(int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, wt);
    findTurnaroundTime(n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    // Call Gantt chart
    printGanttChart(n, bt);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];

    printf("Enter the burst times for the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    findAvgTime(n, bt);

    return 0;
}

