#include <stdio.h>
void RoundRobin(int n, int burst_time[], int quantum) {
    int wait_time = 0, turnaround_time = 0;
    int remaining_burst_time[n];
    float avg_wait_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }
    int time = 0;
    while (1) {
        int completed = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                completed = 0;
                if (remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else {
                    time += remaining_burst_time[i];
                    wait_time += time - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (completed) break;
    }
    for (int i = 0; i < n; i++) {
        turnaround_time += burst_time[i];
        avg_turnaround_time += turnaround_time;
    }
    avg_wait_time = (float)wait_time / n;
    avg_turnaround_time = (float)avg_turnaround_time / n;
    printf("Round Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Average Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n];
    printf("Enter the burst times of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    RoundRobin(n, burst_time, quantum);
    return 0;
}