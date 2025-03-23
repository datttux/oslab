#include <stdio.h>
#include <stdlib.h>

#define FRAME_COUNT 4 

void fifo(int pages[], int pageCount) {
    int frames[FRAME_COUNT];
    int pageFaults = 0;
    int i, j;
    int isPresent;

    for (i = 0; i < FRAME_COUNT; i++) {
        frames[i] = -1;
    }

    printf("FIFO Page Replacement:\n");

    for (i = 0; i < pageCount; i++) {
        isPresent = 0;

        for (j = 0; j < FRAME_COUNT; j++) {
            if (frames[j] == pages[i]) {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent) {
            frames[pageFaults % FRAME_COUNT] = pages[i];
            pageFaults++;
        }

        printf("After accessing page %d: ", pages[i]);
        for (j = 0; j < FRAME_COUNT; j++) {
            if (frames[j] == -1) {
                printf(" _ ");
            } else {
                printf(" %d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 3};
    int pageCount = sizeof(pages) / sizeof(pages[0]);

    fifo(pages, pageCount);

    return 0;
}
