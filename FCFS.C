#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[])
 {  int i;
    wt[0] = 0;
     // Waiting time for the first process is 0
    for(i=1;i<n;i++)
    {
	wt[i] = bt[i - 1] + wt[i - 1]; // Corrected index
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    int i;
    for(i= 0;i<n;i++)

     {
	tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
    }
}

void findAvgTime(int processes[],int n,int bt[]) {
    int total_wt=0;
    int total_tat=0;
    int i;
    int wt[100],tat[100];
    float avg_wt,avg_tat;

    findWaitingTime(n,bt,wt);
    findTurnAroundTime(n, bt, wt, tat);

    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");
    for(i=0;i<n;i++) {
	total_wt+=wt[i];
	total_tat+=tat[i];
	printf(" %d\t\t %d\t\t %d\t\t %d\n", (i + 1), bt[i], wt[i], tat[i]);
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}

int main() {
    int processes[]={ 1, 2, 3 };
    int n=sizeof(processes)/sizeof(processes[0]);
    int burst_time[] = { 10, 5, 8 };

    findAvgTime(processes,n,burst_time);
    return 0;
}