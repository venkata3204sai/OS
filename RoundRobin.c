//ROund robin
#include <stdio.h>

// Function to calculate and display the Round Robin scheduling
void roundRobinScheduling(int NOP, int at[], int bt[], int quant);

int main() {
    int NOP, quant;

    // Input the total number of processes
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);

    // Declare arrays for arrival time and burst time
    int at[NOP], bt[NOP];

    // Input Arrival and Burst time for each process
    for(int i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
    }

    // Input the time quantum
    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &quant);

    // Call the round robin scheduling function
    roundRobinScheduling(NOP, at, bt, quant);

    return 0;
}

void roundRobinScheduling(int NOP, int at[], int bt[], int quant) {
    int i, sum = 0, count = 0, y, wt = 0, tat = 0;
    int temp[NOP];

    // Copy burst times into temp array
    for(i = 0; i < NOP; i++) {
        temp[i] = bt[i];
    }

    y = NOP;  // Set the number of remaining processes to NOP

    // Print header for the output table
    printf("\nProcess No \t Burst Time \t Turnaround Time \t Waiting Time\n");

    // Execute the round-robin scheduling
    for(sum = 0, i = 0; y != 0;) {
        if(temp[i] <= quant && temp[i] > 0) {
            // Process finishes within the time quantum
            sum += temp[i];
            temp[i] = 0;  // Mark process as completed
            count = 1;
        } else if(temp[i] > 0) {
            // Process needs more time
            temp[i] -= quant;
            sum += quant;
        }

        // Process has finished execution
        if(temp[i] == 0 && count == 1) {
            y--;  // One process is finished
            printf("Process No[%d] \t\t %d \t\t\t %d \t\t\t %d\n", 
                    i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i];  // Add waiting time
            tat += sum - at[i];  // Add turnaround time
            count = 0;  // Reset for the next process
        }

        // Move to the next process
        if(i == NOP - 1) {
            i = 0;  // Loop back to the first process
        } else if(at[i + 1] <= sum) {
            i++;  // Proceed to the next process if it has arrived
        } else {
            i = 0;  // Go back to the first process
        }
    }

    // Calculate and display the average waiting time and turnaround time
    float avg_wt = wt * 1.0 / NOP;
    float avg_tat = tat * 1.0 / NOP;

    printf("\nAverage Turnaround Time: \t%f", avg_tat);
    printf("\nAverage Waiting Time: \t%f\n", avg_wt);
}