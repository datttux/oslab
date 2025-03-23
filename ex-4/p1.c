#include <stdio.h>
void FCFS(int n, int burst_time[]) {
    int wait_time = 0, turnaround_time = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i< n; i++) {
        wait_time += turnaround_time;
        turnaround_time += burst_time[i];
        avg_wait_time += wait_time;
        avg_turnaround_time += turnaround_time;
    }
    printf("FCFS Scheduling:\n");
    printf("Average Waiting Time: %.2f\n", avg_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n];
    printf("Enter the burst times of the processes:\n");
    for (int i = 0; i< n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    FCFS(n, burst_time);
    return 0;
}
