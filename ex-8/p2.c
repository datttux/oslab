#include <stdio.h>
#define PARTITION_COUNT 5
#define PROCESS_COUNT 4

void worstFit(int partitions[], int partitionCount, int processes[], int processCount) {
 int allocation[processCount];
 for (int i = 0; i < processCount; i++) {
 allocation[i] = -1;
 }
 for (int i = 0; i < processCount; i++) {
 int maxIndex = -1;
 int maxSize = -1;
 for (int j = 0; j < partitionCount; j++) {
 if (partitions[j] >= processes[i] && partitions[j] > maxSize) {
 maxSize = partitions[j];
 maxIndex = j;
 }
 }
 if (maxIndex != -1) {
 allocation[i] = maxIndex;
 partitions[maxIndex] -= processes[i];
 }
 }
 printf("\nWorst Fit Allocation:\n");
 for (int i = 0; i < processCount; i++) {
 if (allocation[i] != -1) {
 printf("Process %d allocated to Partition %d\n", i + 1, allocation[i] + 1);
 } else {
 printf("Process %d not allocated\n", i + 1);
 }
 }
}

int main() {
 int partitions[PARTITION_COUNT] = {100, 500, 200, 300, 600};
 int processes[PROCESS_COUNT] = {212, 417, 112, 426};
 worstFit(partitions, PARTITION_COUNT, processes, PROCESS_COUNT);
 return 0;
}
