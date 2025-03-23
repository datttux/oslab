#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10  

typedef struct {
    int block[MAX_BLOCKS];  
    int allocated[MAX_BLOCKS];  
    int next[MAX_BLOCKS];  
} Disk;

void linkedAllocation(Disk *disk, int fileSize) {
    int blocksNeeded = (fileSize + MAX_BLOCKS - 1) / MAX_BLOCKS;
    int prevBlock = -1;

    for (int i = 0; i < blocksNeeded; i++) {
        int blockIndex = -1;

        for (int j = 0; j < MAX_BLOCKS; j++) {
            if (disk->allocated[j] == 0) {
                blockIndex = j;
                break;
            }
        }

        if (blockIndex == -1) {
            printf("No available blocks for allocation\n");
            return;
        } else {
            disk->allocated[blockIndex] = 1;

            if (prevBlock != -1) {
                disk->next[prevBlock] = blockIndex;
            }

            disk->next[blockIndex] = -1;

            if (prevBlock == -1) {
                printf("Allocating block %d to file (Start of chain)\n", blockIndex);
            } else {
                printf("Allocating block %d to file (Linked to block %d)\n", blockIndex, prevBlock);
            }

            prevBlock = blockIndex;
        }
    }
}

int main() {
    Disk disk = {0};
    int fileSize = 6;  
    linkedAllocation(&disk, fileSize);
    return 0;
}
