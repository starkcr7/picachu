#include <stdio.h>
#include <stdlib.h>

// Define the size of the buffer
#define BUFFER_SIZE 5

// Initialize a mutex to 1
int mutex = 1;
// Number of full slots as 0
int full = 0;
// Number of empty slots as size of buffer
int empty = BUFFER_SIZE, x = 0;
// Buffer array to store produced items
int buffer[BUFFER_SIZE];

// Function to produce an item and add it to the buffer
void producer() {
    // Decrease mutex value by 1
    --mutex;
    // Increase the number of full slots by 1
    ++full;
    // Decrease the number of empty slots by 1
    --empty;
    // Item produced
    x++;
    buffer[full - 1] = x;  // Add item to the buffer
    printf("\nProducer produces item %d", x);
    // Increase mutex value by 1
    ++mutex;
}

// Function to consume an item and remove it from buffer
void consumer() {
    // Decrease mutex value by 1
    --mutex;
    // Decrease the number of full slots by 1
    --full;
    // Increase the number of empty slots by 1
    ++empty;
    printf("\nConsumer consumes item %d", buffer[full]);
    buffer[full] = 0;  // Remove item from the buffer
    // Increase mutex value by 1
    ++mutex;
}

// Function to show the current state of the buffer
void show() {
    printf("\nCurrent Buffer State:\n");
    printf("[ ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", buffer[i]);
    }
    printf("]\n");
}

// Driver Code
int main() {
    int n, i;
    // Initialize the buffer to 0
    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }

    printf("\n1. Press 1 for Producer");
    printf("\n2. Press 2 for Consumer");
    printf("\n3. Press 3 for Show Buffer State");
    printf("\n4. Press 4 for Exit");

    // Infinite loop to simulate continuous producer-consumer problem
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        
        // Switch Cases
        switch (n) {
            case 1:
                // If mutex is 1 and empty is non-zero, then it is possible to produce
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    // Otherwise, print buffer is full
                    printf("Buffer is full!");
                }
                break;
            case 2:
                // If mutex is 1 and full is non-zero, then it is possible to consume
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    // Otherwise, print Buffer is empty
                    printf("Buffer is empty!");
                }
                break;
            case 3:
                // Show the current state of the buffer
                show();
                break;
            // Exit Condition
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, 3, or 4.");
                break;
        }
    }

    return 0;
}
