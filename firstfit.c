#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 25
#define MAX_FILES 25

int main() {
    int frag[MAX_FILES], b[MAX_BLOCKS], f[MAX_FILES], bf[MAX_BLOCKS], ff[MAX_FILES];
    int nb, nf, i, j, temp;

    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        ff[i] = -1; // Initialize file-to-block mapping to -1 (not allocated)
        for (j = 1; j <= nb; j++) {
            if (!bf[j] && b[j] >= f[i]) { // If block is free and can accommodate file
                ff[i] = j;
                bf[j] = 1; // Mark block as allocated
                frag[i] = b[j] - f[i]; // Calculate fragmentation
                break;
            }
        }
        if (ff[i] == -1) { // If no suitable block found for file
            printf("Error: No suitable block found for File %d\n", i);
            exit(1);
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }

    return 0;
}
