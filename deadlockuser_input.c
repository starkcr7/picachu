#include <stdio.h>

// Function to find the need matrix
void calculateNeed(int need[][10], int max[][10], int alloc[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// Function to check if all processes can finish
int isSafeState(int processes[], int avail[], int max[][10], int alloc[][10], int n, int m) {
    int need[n][10];
    calculateNeed(need, max, alloc, n, m);

    int finish[n];
    int safeSeq[n];
    int work[m];
    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int p = 0; p < n; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += alloc[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }

    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
        if (i != n - 1)
            printf("-> ");
    }
    printf("\n");
    return 1;
}

int main() {
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int processes[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i;
    }

    int alloc[n][10];
    int max[n][10];
    int avail[10];

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    isSafeState(processes, avail, max, alloc, n, m);

    return 0;
}
