#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 30

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", frames[i]);
        }
    }
    printf("\n");
}

int isPageInFrames(int page, int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1;  // Page found in frames
        }
    }
    return 0;  // Page not found in frames
}

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int nFrames, nPages, pageFaults = 0;
    int currentIndex = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &nFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &nPages);

    printf("Enter the reference string (pages):\n");
    for (int i = 0; i < nPages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames to -1 indicating they are empty
    for (int i = 0; i < nFrames; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < nPages; i++) {
        printf("Page %d: ", pages[i]);
        
        if (!isPageInFrames(pages[i], frames, nFrames)) {
            frames[currentIndex] = pages[i];
            currentIndex = (currentIndex + 1) % nFrames;
            pageFaults++;
            printFrames(frames, nFrames);
        } else {
            printf("No page fault\n");
        }
    }

    printf("\nTotal number of page faults: %d\n", pageFaults);

    return 0;
}
