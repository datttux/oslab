#include <stdio.h>
#include <stdbool.h>

#define P 5  
#define R 3  

bool isSafeState(int processes[], int avail[], int max[][R], int allot[][R], int need[][R]) {
    int work[R], finish[P];
    int safeSeq[P];

    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }
    for (int i = 0; i < P; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < P) {
        bool found = false;

        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {
                bool canFinish = true;

                for (int j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    for (int j = 0; j < R; j++) {
                        work[j] += allot[p][j];
                    }
                    finish[p] = 1;
                    safeSeq[count++] = p;
                    found = true;
                }
            }
        }

        if (!found) {
            return false;
        }
    }

    printf("Safe Sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return true;
}

bool requestResources(int p, int request[], int processes[], int avail[], int max[][R], int allot[][R], int need[][R]) {
    for (int i = 0; i < R; i++) {
        if (request[i] > need[p][i]) {
            printf("Error: Process has exceeded its maximum claim\n");
            return false;
        }
    }

    for (int i = 0; i < R; i++) {
        if (request[i] > avail[i]) {
            printf("Error: Resources are not available\n");
            return false;
        }
    }

    for (int i = 0; i < R; i++) {
        avail[i] -= request[i];
        allot[p][i] += request[i];
        need[p][i] -= request[i];
    }

    if (isSafeState(processes, avail, max, allot, need)) {
        printf("Resources allocated successfully\n");
        return true;
    } else {
        for (int i = 0; i < R; i++) {
            avail[i] += request[i];
            allot[p][i] -= request[i];
            need[p][i] += request[i];
        }
        printf("Resources could not be allocated due to unsafe state\n");
        return false;
    }
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {3, 3, 2};

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allot[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int need[P][R];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    if (isSafeState(processes, avail, max, allot, need)) {
        printf("System is in a safe state\n");
    } else {
        printf("System is in an unsafe state\n");
    }

    int request[] = {1, 0, 2};
    requestResources(1, request, processes, avail, max, allot, need);

    return 0;
}
