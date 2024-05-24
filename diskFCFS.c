#include <stdio.h>
#include <stdlib.h> // Included for abs() function

int main() {
    int queue[20], n, head, seek = 0, max, diff;
    float avg;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);

    printf("Enter the size of the queue request: ");
    scanf("%d", &n);

    // Check if n is within the limit
    if (n > 19) {
        printf("Queue size should not exceed 19\n");
        return 1;
    }

    printf("Enter the request queue :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        // Check if the disk positions are within the range
        if (queue[i] < 0 || queue[i] > max) {
            printf("Disk position out of range\n");
            return 1;
        }
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Check if the head position is within the range
    if (head < 0 || head > max) {
        printf("Initial head position out of range\n");
        return 1;
    }

    // Process the initial head to the first request
    diff = abs(queue[0] - head);
    seek += diff;
    printf("Disk head moves from %d to %d with seek %d\n", head, queue[0], diff);

    // Process the queue
    for (int j = 0; j < n - 1; j++) {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }

    printf("Total seek time is %d\n", seek);
    avg = (float)seek / n;
    printf("Average seek time is %.2f\n", avg);

    return 0;
}
