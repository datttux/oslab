#include <stdio.h>
#define PARTITION_COUNT 5
#define PROCESS_COUNT 4

void bestFit(int partitions[], int partitionCount, int processes[], int processCount) {
 int allocation[processCount];
 for (int i = 0; i < processCount; i++) {
 allocation[i] = -1;
 }
 for (int i = 0; i < processCount; i++) {
 int minIndex = -1;
 int minSize = 9999999;
 for (int j = 0; j < partitionCount; j++) {
 if (partitions[j] >= processes[i] && partitions[j] < minSize) {
 minSize = partitions[j];
 minIndex = j;
 }
 }
 if (minIndex != -1) {
 allocation[i] = minIndex;
 partitions[minIndex] -= processes[i];
 }
 }
 printf("\nBest Fit Allocation:\n");
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
 bestFit(partitions, PARTITION_COUNT, processes, PROCESS_COUNT);
 return 0;
}
