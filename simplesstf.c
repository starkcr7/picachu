#include <stdio.h>
#include <stdlib.h>

// Calculates difference of each track number with the head position
void calculatedifference(int request[], int head, int diff[][2], int n) {
    for (int i = 0; i < n; i++) {
        diff[i][0] = abs(head - request[i]);
    }
}

// Find unaccessed track which is at minimum distance from head
int findMIN(int diff[][2], int n) {
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < n; i++) {
        if (!diff[i][1] && minimum > diff[i][0]) {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[], int head, int n) {
    if (n == 0) {
        return;
    }
    
    // Create array for difference and accessed flag
    int diff[n][2];
    for (int i = 0; i < n; i++) {
        diff[i][0] = diff[i][1] = 0;
    }
    
    // Count total number of seek operations
    int seekcount = 0;
    
    // Stores sequence in which disk access is done
    int seeksequence[n + 1];
    
    for (int i = 0; i < n; i++) {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;
        
        // Increase the total count
        seekcount += diff[index][0];
        
        // Accessed track is now new head
        head = request[index];
    }
    seeksequence[n] = head;
    
    printf("Total seek time = %d\n", seekcount);
    printf("Seek sequence is:\n");
    
    // Print the sequence
    for (int i = 0; i <= n; i++) {
        printf("%d\n", seeksequence[i]);
    }
}

// Driver code
int main() {
    int n = 8;
    int proc[] = {176, 79, 34, 60, 92, 11, 41, 114};
    
    shortestSeekTimeFirst(proc, 50, n);
    
    return 0;
}
