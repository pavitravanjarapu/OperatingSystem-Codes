#include <stdio.h>
#include <stdlib.h>

int main() {
    int total, hungry, choice;
    int philosophers[10];  // max 10 philosophers supported
    int i, j, k = 0;

    printf("DINING PHILOSOPHER PROBLEM\n");
    printf("Enter the total no. of philosophers: ");
    scanf("%d", &total);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for (i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position: ", i + 1);
        scanf("%d", &philosophers[i]);
    }

    do {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nAllow one philosopher to eat at any time\n");
                for (i = 0; i < hungry; i++) {
                    printf("P %d is granted to eat\n", philosophers[i]);
                    for (j = 0; j < hungry; j++) {
                        if (j != i)
                            printf("P %d is waiting\n", philosophers[j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\nAllow two philosophers to eat at same time\n");
                k = 1;
                for (i = 0; i < hungry - 1; i++) {
                     for (j = i + 1; j < hungry; j++) {
                        printf("Combination %d\n", k++);
                        printf("P %d and P %d are granted to eat\n", philosophers[i], philosophers[j]);
                        for (int m = 0; m < hungry; m++) {
                            if (m != i && m != j)
                                printf("P %d is waiting\n", philosophers[m]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
