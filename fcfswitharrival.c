#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], ct[20], i, j;
    float avwt = 0, avtat = 0;
    
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);
    
    printf("Enter Process Arrival Times\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
    }
    
    printf("Enter Process Burst Times\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    // Calculate completion time, waiting time and turnaround time
    int currentTime = 0;
    for (i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];
        }
        wt[i] = currentTime - at[i];
        ct[i] = currentTime + bt[i];
        tat[i] = ct[i] - at[i];
        currentTime += bt[i];
    }
    
    printf("\nP#\tat\tbt\twt\ttat\n");
    
    for (i = 0; i < n; i++) {
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    
    avwt /= n;
    avtat /= n;
    
    printf("Average Waiting Time: %.2f\n", avwt);
    printf("Average Turnaround Time: %.2f\n", avtat);
    
    return 0;
}
