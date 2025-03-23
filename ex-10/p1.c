#include <stdio.h>
#include <stdlib.h>

#define FRAME_COUNT 4  
#define PAGE_COUNT 8   
#define PAGE_SIZE 4    

int pageTable[PAGE_COUNT] = {-1};  

void pagingSimulation(int processPages[], int pageCount) {
    int physicalMemory[FRAME_COUNT][PAGE_SIZE] = {0};  
    int pageFaults = 0;
    int i, pageIndex, frameIndex;

    printf("Paging Simulation:\n");

    for (i = 0; i < pageCount; i++) {
        pageIndex = processPages[i];

        if (pageTable[pageIndex] != -1) {
            frameIndex = pageTable[pageIndex];
            printf("Page %d is already in frame %d\n", pageIndex, frameIndex);
        } else {
            int foundEmptyFrame = 0;

            for (frameIndex = 0; frameIndex < FRAME_COUNT; frameIndex++) {
                if (physicalMemory[frameIndex][0] == 0) { 
                    pageTable[pageIndex] = frameIndex;
                    physicalMemory[frameIndex][0] = pageIndex;
                    foundEmptyFrame = 1;
                    pageFaults++;
                    printf("Page %d caused a page fault. Allocating to frame %d\n", pageIndex, frameIndex);
                    break;
                }
            }

            if (!foundEmptyFrame) {
                frameIndex = 0;
                pageTable[pageIndex] = frameIndex;
                physicalMemory[frameIndex][0] = pageIndex;
                printf("Page %d caused a page fault. Replacing frame %d\n", pageIndex, frameIndex);
                pageFaults++;
            }
        }

        printf("Current Page Table:\n");
        for (int j = 0; j < PAGE_COUNT; j++) {
            printf("Page %d -> Frame %d\n", j, pageTable[j]);
        }

        printf("Current Physical Memory:\n");
        for (int j = 0; j < FRAME_COUNT; j++) {
            if (physicalMemory[j][0] != 0) {
                printf("Frame %d: Page %d\n", j, physicalMemory[j][0]);
            } else {
                printf("Frame %d: Empty\n", j);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int processPages[] = {2, 4, 1, 2, 5, 6, 3, 2, 4, 1};  
    int pageCount = sizeof(processPages) / sizeof(processPages[0]);  

    pagingSimulation(processPages, pageCount);

    return 0;
}
