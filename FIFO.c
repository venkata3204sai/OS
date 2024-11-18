//FIFO page replacement                                                                                                                                                #include<stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    int temp[100];
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
    

    for (m = 0; m < frames; m++) {
        temp[m] = -1; // Initialize frames to -1 (indicating empty)
    }
    
    for (m = 0; m < pages; m++) {
        s = 0; // Reset the flag for each incoming page
        
        // Check if the page is already in one of the frames
        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++; // Page is found in frames
                pageFaults--; // Decrease pageFaults count
            }
        }
        
        pageFaults++; // Increment pageFaults for the current page
        
        // If there is space in the frames and the page is not found
        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m]; // Add page to frames
        }
        // If the page is not found and frames are full
        else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m]; // Replace page
        }
        
        // Print the current state
        printf("\n%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1) {
                printf("%d\t\t", temp[n]); // Print current frame
            } else {
                printf("-\t\t"); // Indicate empty frame
            }
        }
    }
    
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}