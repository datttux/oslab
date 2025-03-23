#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10  

typedef struct {
    int block[MAX_BLOCKS];  
    int allocated[MAX_BLOCKS];  
} Disk;

void sequentialAllocation(Disk *disk, int fileSize) {
    int blocksNeeded = (fileSize + MAX_BLOCKS - 1) / MAX_BLOCKS;
    
    for (int i = 0; i < blocksNeeded; i++) {
        if (disk->allocated[i] == 1) {
            printf("Block %d already allocated!\n", i);
        } else {
            disk->allocated[i] = 1;
            printf("Allocating block %d to file\n", i);
        }
    }
}

int main() {
    Disk disk = {0};
    int fileSize = 15;  
    sequentialAllocation(&disk, fileSize);
    return 0;
}
