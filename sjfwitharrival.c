#include <stdio.h>

int main() {
    // Matrix for storing Process Id, Arrival Time, Burst Time, 
    // Waiting Time, and Turnaround Time.
    int A[100][5];
    int i, j, n, total_wt = 0, total_tat = 0, index, temp;
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter Arrival Time and Burst Time:\n");
    // User Input Arrival Time and Burst Time and allocating Process Id.
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &A[i][1]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &A[i][2]);
        A[i][0] = i + 1;
    }
    
    // Sorting processes according to their Arrival Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1]) {
                index = j;
            }
        }
        // Swapping Arrival Time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
        
        // Swapping Burst Time
        temp = A[i][2];
        A[i][2] = A[index][2];
        A[index][2] = temp;
        
        // Swapping Process Id
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    
    // Calculating Waiting Time and Turnaround Time
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < A[i][1]) {
            current_time = A[i][1];
        }
        A[i][3] = current_time - A[i][1]; // Waiting Time
        A[i][4] = A[i][3] + A[i][2]; // Turnaround Time
        current_time += A[i][2];
        
        total_wt += A[i][3];
        total_tat += A[i][4];
    }
    
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    
    printf("P\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3], A[i][4]);
    }
    
    printf("Average Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f", avg_tat);
    
    return 0;
}
