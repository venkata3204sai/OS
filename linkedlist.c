#include <stdio.h>
#include <stdlib.h>

void main() {
    int f[50], p, i, st, len, j, c, k, a;

    // Initialize the file allocation table
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter blocks already allocated:\n");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1; // Mark the allocated blocks
    }

    while (1) { // Replace goto with a while loop for better structure
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);
        k = len;

        if (f[st] == 0) { // Check if starting block is free
            for (j = st; j < (st + k); j++) {
                if (j >= 50) { // Check bounds
                    printf("Cannot allocate beyond block 49\n");
                    break;
                }
                if (f[j] == 0) {
                    f[j] = 1; // Mark the block as allocated
                    printf("%d -------->%d\n", j, f[j]);
                } else {
                    printf("%d Block is already allocated\n", j);
                    k++; // Increase length to find next free block
                }
            }
        } else {
            printf("%d starting block is already allocated\n", st);
        }

        printf("Do you want to enter more file (Yes - 1/No - 0): ");
        scanf("%d", &c);
        if (c == 0) {
            break; // Exit the loop if user chooses not to continue
        }
    }

    exit(0); // Exit the program
}