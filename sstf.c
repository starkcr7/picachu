#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, seek = 0, max, diff;
    float avg;
    int visited[20] = {0};

    printf("Enter the max range of disk: ");
    scanf("%d", &max);

    printf("Enter the size of queue request: ");
    scanf("%d", &n);

    printf("Enter the queue of disk positions to be read: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        int min = max + 1, minIndex;
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                diff = abs(queue[j] - head);
                if (diff < min) {
                    min = diff;
                    minIndex = j;
                }
            }
        }
        visited[minIndex] = 1;
        seek += abs(queue[minIndex] - head);
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[minIndex], abs(queue[minIndex] - head));
        head = queue[minIndex];
    }

    printf("Total seek time is %d\n", seek);
    avg = (float) seek / n;
    printf("Average seek time is %f\n", avg);

    return 0;
}
