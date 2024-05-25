#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], p, i, st, len, j, c, k, a;

    // Initialize all blocks to 0 (free)
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    // Input for already allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50) {
            f[a] = 1;
        } else {
            printf("Block number %d is out of range and will be ignored.\n", a);
        }
    }

    do {
        // Input for starting block and length of the new file
        printf("Enter index of the starting block and length: ");
        scanf("%d%d", &st, &len);
        k = len;

        // Check if the starting block is free
        if (st >= 0 && st < 50 && f[st] == 0) {
            for (j = st; j < (st + k) && j < 50; j++) {
                if (f[j] == 0) {
                    f[j] = 1;
                    printf("%d --------> %d\n", j, f[j]);
                } else {
                    printf("%d Block is already allocated\n", j);
                    k++;
                }
            }
        } else {
            printf("%d starting block is already allocated or out of range\n", st);
        }

        // Ask user if they want to enter more files
        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}
