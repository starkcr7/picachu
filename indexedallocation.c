#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 50

void initialize_disk(int f[], int size);
void allocate_blocks(int f[], int index, int blocks[], int n);
void display_allocation(int index, int blocks[], int n);
int is_block_allocated(int f[], int index);
int allocate_index_block(int f[], int *index);
int get_blocks(int f[], int blocks[], int n);

int main() {
    int f[DISK_SIZE], index, n, blocks[DISK_SIZE], choice;

    initialize_disk(f, DISK_SIZE);

    while (1) {
        if (!allocate_index_block(f, &index)) {
            continue;
        }

        printf("Enter the number of blocks needed: ");
        scanf("%d", &n);

        if (get_blocks(f, blocks, n)) {
            allocate_blocks(f, index, blocks, n);
            display_allocation(index, blocks, n);
        } else {
            printf("Some blocks are already allocated. Try again.\n");
        }

        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
    }

    return 0;
}

void initialize_disk(int f[], int size) {
    for (int i = 0; i < size; i++)
        f[i] = 0;
}

void allocate_blocks(int f[], int index, int blocks[], int n) {
    f[index] = 1;  // Mark the index block as allocated
    for (int i = 0; i < n; i++) {
        f[blocks[i]] = 1;  // Mark the blocks as allocated
    }
}

void display_allocation(int index, int blocks[], int n) {
    printf("Allocated\n");
    printf("File Indexed\n");
    for (int i = 0; i < n; i++) {
        printf("%d-------->%d : %d\n", index, blocks[i], 1);
    }
}

int is_block_allocated(int f[], int index) {
    return f[index] == 1;
}

int allocate_index_block(int f[], int *index) {
    printf("Enter the index block: ");
    scanf("%d", index);

    if (is_block_allocated(f, *index)) {
        printf("%d index is already allocated\n", *index);
        return 0;
    }
    return 1;
}

int get_blocks(int f[], int blocks[], int n) {
    int count = 0;
    printf("Enter the blocks:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
        if (!is_block_allocated(f, blocks[i])) {
            count++;
        }
    }
    return count == n;
}
