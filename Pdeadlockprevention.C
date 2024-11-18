#include <stdio.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    // Allocation matrix
    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Maximum requirement matrix
    int max[5][3] = {
	{7, 5, 3},
	{3, 2, 2},
	{9, 0, 2},
	{2, 2, 2},
	{4, 3, 3}
    };

    // Available resources
    int avail[3] = {3, 3, 2};

    // Finish array to keep track of finished processes
    int f[5], ans[5], ind = 0;
    int need[5][3];
    int k,i,j,y,flag=1;
    for (k = 0;k<n;k++) {
	f[k] = 0; // Initialize finish array to 0
    }

    // Need matri
    for (i = 0;i<n;i++) {
	for(j = 0;j < m;j++) {
	    need[i][j] = max[i][j] - alloc[i][j]; // Calculate need
	}
    }

    // Banker's algorithm to find safe sequence
    for (k = 0; k < n; k++) {
	for (i = 0; i < n; i++) {
	    if (f[i] == 0) { // Process not finished
		int flag = 0;
		for (j = 0; j < m; j++) {
		    if (need[i][j] > avail[j]) { // Check if need can be satisfied
			flag = 1;
			break;
		    }
		}
		if (flag == 0) { // If the process can be executed
		    ans[ind++] = i; // Add to safe sequence
		    for (y = 0; y < m; y++) {
			avail[y] += alloc[i][y]; // Release allocated resources
		    }
		    f[i] = 1; // Mark process as finished
		}
	    }
	}
    }

    // Check if all processes are finished
    for (i = 0;i < n; i++) {
        if (f[i] == 0) {
            flag = 0; // If any process is not finished
            printf("The following system is not safe\n");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
	for (i= 0; i < n - 1; i++)
            printf("P%d -> ", ans[i]);
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}