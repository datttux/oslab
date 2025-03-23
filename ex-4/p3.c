#include <stdio.h>
void Priority(int n, int burst_time[], int priority[]) {
    int wait_time = 0, turnaround_time = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int temp_burst, temp_priority;
    for (int i = 0; i< n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] >priority[j + 1]) {
                temp_burst = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp_burst;
                temp_priority = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp_priority;
            }
        }
    }
    for (int i = 0; i< n; i++) {
        wait_time += turnaround_time;
        turnaround_time += burst_time[i];
        avg_wait_time += wait_time;
        avg_turnaround_time += turnaround_time;
    }
    printf("Priority Scheduling:\n");
    printf("Average Waiting Time: %.2f\n", avg_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], priority[n];
    printf("Enter the burst times and priorities of the processes:\n");
    for (int i = 0; i< n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    Priority(n, burst_time, priority);
    return 0;
}