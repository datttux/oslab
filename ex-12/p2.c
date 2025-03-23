#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10  
#define INDEX_SIZE 3  

typedef struct {
    int block[MAX_BLOCKS];  
    int allocated[MAX_BLOCKS];  
    int index[INDEX_SIZE];  
} Disk;

void indexedAllocation(Disk *disk, int fileSize) {
    int blocksNeeded = (fileSize + MAX_BLOCKS - 1) / MAX_BLOCKS;
    
    for (int i = 0; i < blocksNeeded; i++) {
        if (disk->allocated[i] == 1) {
            printf("Block %d already allocated!\n", i);
        } else {
            disk->allocated[i] = 1;
            disk->index[i % INDEX_SIZE] = i;  
            printf("Allocating block %d to file (Index: %d)\n", i, i % INDEX_SIZE);
        }
    }
}

int main() {
    Disk disk = {0};
    int fileSize = 12;  
    indexedAllocation(&disk, fileSize);
    return 0;
}
