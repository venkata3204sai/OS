#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100];
    int c;

    // Prompt user for input filename to read
    printf("Enter the filename to open for reading:\n");
    scanf("%s", filename);
    
    // Open the file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    // Prompt user for output filename to write
    printf("Enter the filename to open for writing:\n");
    scanf("%s", filename);
    
    // Open the file for writing
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s\n", filename);
        fclose(fptr1); // Close the first file before exiting
        exit(0);
    }

    // Copy contents from fptr1 to fptr2
    while ((c = fgetc(fptr1)) != EOF) {
        fputc(c, fptr2);
    }

    printf("\nContents copied to %s\n", filename);

    // Close both files
    fclose(fptr1);
    fclose(fptr2);

    return 0;
}