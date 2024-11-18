#include <stdio.h>

int main() {
    int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], done[5], terminate = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &c);

    printf("Enter allocation of resources for all processes (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the maximum resources required by each process (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (i = 0; i < c; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nNeed resources matrix is:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];  // Corrected calculation
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++) {
        done[i] = 0;  // Initialize done array
    }

    while (count < p) {
        terminate = 0;  // Reset terminate at the start of each iteration
        for (i = 0; i < p; i++) {
            if (done[i] == 0) {  // Check if process i is not yet done
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j]) {  // Check if the needed resources are greater than available
                        break;  // Break if any need cannot be satisfied
                    }
                }
                if (j == c) {  // If we checked all resources and found them sufficient
                    safe[count] = i;  // Add process to safe sequence
                    done[i] = 1;  // Mark process as done
                    for (j = 0; j < c; j++) {
                        available[j] += alc[i][j];  // Release allocated resources back to available
                    }
                    count++;  // Increment count of completed processes
                    terminate = 0;  // Reset terminate since we found a process to execute
                } else {
                    terminate++;  // Increment terminate if we couldn't satisfy this process
                }
            }
        }
        if (terminate == p) {  // If all processes were checked and none could proceed
            printf("Safe sequence does not exist.\n");
            break;  // Exit the loop if no safe sequence can be found
        }
    }

    if (terminate != p) {  // If we found a safe sequence
        printf("\nAvailable resources after completion:\n");
        for (i = 0; i < c; i++) {
            printf("%d\t", available[i]);  // Print available resources
        }
        printf("\nSafe sequence is:\n");
        for (i = 0; i < count; i++) {
            printf("P%d\t", safe[i]);  // Print the safe sequence of processes
        }
        printf("\n");
    }

    return 0;
}