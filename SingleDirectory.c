#include <stdio.h>
#include <string.h>

void main() {
    int nf = 0; // Number of files
    int i, ch; // Loop counters and choice
    char mdname[50]; // Directory name
    char fname[10][50]; // Array to store file names
    char name[50]; // File name input

    // Clear the screen (not standard, but included for compatibility)
    // clrscr(); // Uncomment if using Turbo C/C++

    // Input directory name
    printf("Enter the directory name: ");
    scanf("%s", mdname);

    // Input the number of files
    printf("Enter the number of files (max 10): ");
    scanf("%d", &nf);

    // Ensure nf does not exceed the limit of fname array
    if (nf > 10) {
        printf("Maximum number of files is 10. Setting to 10.\n");
        nf = 10;
    }

    // Loop to enter file names
    do {
        printf("Enter file name to be created: ");
        scanf("%s", name);

        // Check for duplicate file names
        for (i = 0; i < nf; i++) {
            if (!strcmp(name, fname[i])) {
                printf("There is already a file named %s\n", name);
                break;
            }
        }

        // If the file name is unique, add it to the list
        if (i == nf) {
            strcpy(fname[nf++], name); // Add file name and increment count
        }

        // Ask if the user wants to enter another file
        printf("Do you want to enter another file (yes - 1 or no - 0): ");
        scanf("%d", &ch);

    } while (ch == 1 && nf < 10); // Limit to 10 files

    // Output the directory name and file names
    printf("Directory name is: %s\n", mdname);
    printf("File names are:\n");
    for (i = 0; i < nf; i++) {
        printf("%s\n", fname[i]);
    }

    // Wait for user input before closing (not standard, but included for compatibility)
    // getch(); // Uncomment if using Turbo C/C++
}