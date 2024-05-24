#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) { // loop will run n times
        if (fork() == 0) {
            printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
            exit(0);
        }
    }

    for (i = 0; i < n; i++)
        wait(NULL);

    return 0;
}
