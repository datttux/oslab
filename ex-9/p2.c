#include <stdio.h>
#include <stdlib.h>

#define FRAME_COUNT 4 

void lfu(int pages[], int pageCount) {
    int frames[FRAME_COUNT];
    int frequency[FRAME_COUNT] = {0}; 
    int pageFaults = 0;
    int i, j;
    int isPresent, lfuIndex, minFrequency;

    for (i = 0; i < FRAME_COUNT; i++) {
        frames[i] = -1;
    }

    printf("LFU Page Replacement:\n");

    for (i = 0; i < pageCount; i++) {
        isPresent = 0;

        for (j = 0; j < FRAME_COUNT; j++) {
            if (frames[j] == pages[i]) {
                isPresent = 1;
                frequency[j]++;
                break;
            }
        }

        if (!isPresent) {
            lfuIndex = 0;
            minFrequency = frequency[0];

            for (j = 1; j < FRAME_COUNT; j++) {
                if (frequency[j] < minFrequency) {
                    minFrequency = frequency[j];
                    lfuIndex = j;
                }
            }

            frames[lfuIndex] = pages[i];
            frequency[lfuIndex] = 1;
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

    lfu(pages, pageCount);

    return 0;
}
