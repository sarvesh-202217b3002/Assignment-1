// This is the source file for Problem6_202217b3002.c
#include <stdio.h>
#include <stdlib.h>

void calculateFCFS(int n, int burst_time[], int arrival_time[]) {
    int waiting_time[10], turnaround_time[10], completion_time[10];
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    // Completion time for first process
    completion_time[0] = arrival_time[0] + burst_time[0];
    
    // Calculate completion time for all processes
    for (int i = 1; i < n; i++) {
        if (arrival_time[i] > completion_time[i - 1]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i - 1] + burst_time[i];
        }
    }
    
    // Calculate turnaround time and waiting time for all processes
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    
    // Print process details
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", i + 1, waiting_time[i], turnaround_time[i]);
    }
    
    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, burst_time[10], arrival_time[10];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }
    
    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }
    
    calculateFCFS(n, burst_time, arrival_time);
    
    return 0;
}
