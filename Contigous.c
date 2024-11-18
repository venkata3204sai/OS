#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10

int main() {
    int start[MAX_FILES], length[MAX_FILES], num = 0;
    char name[MAX_FILES][20];
    char del[20];
    int ch,found=0;
    int i,j;

    while (1) {
	printf("Contiguous file allocation\n");
	printf("1. File Creation\n");
	printf("2. File Deletion\n");
	printf("3. Display File Allocation Table\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);

	switch (ch) {
	    case 1: {
		if (num >= MAX_FILES) {
		    printf("File limit reached. Cannot create more files.\n");
		    break;
		}
		printf("Enter the name of the file: ");
		scanf("%s", name[num]);
		printf("Enter the start block of the file: ");
		scanf("%d", &start[num]);
		printf("Enter the length of the file: ");
		scanf("%d", &length[num]);
		num++;
		printf("File %s allocated disk space\n", name[num - 1]);
		break;
	    }
	    case 2: {
		printf("Enter the name of the file to be deleted: ");
		scanf("%s", del);
		for (i = 0;i<num;i++) {
		    if (strcmp(name[i], del) == 0) {
			found = 1;
			// Shift files to delete the entry
			for (j=i;j< num - 1;j++) {
			    strcpy(name[j], name[j + 1]);
			    start[j] = start[j + 1];
			    length[j] = length[j + 1];
			}
			num--;
			printf("File %s deleted\n", del);
			break;
		    }
		}
		if (!found) {
		    printf("File %s not found\n", del);
		}
		break;
	    }
	    case 3: {
		printf("File Allocation Table\n");
		printf("File Name\tStart Block\tLength\n");
		for (i = 0;i<num;i++) {
		    printf("%s\t\t%d\t\t%d\n", name[i], start[i], length[i]);
		}
		break;
	    }
	    case 4:
		exit(0);
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }
    return 0;
}   //Contigous