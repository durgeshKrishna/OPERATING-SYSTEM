#include<stdio.h>

void waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
        wait_time[i] = burst_time[i-1] + wait_time[i-1];
}

void turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = burst_time[i] + wait_time[i];
}

void avgtime(int proc[], int n, int burst_time[]) {
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;

    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);

    printf("\n Processes Burst  Waiting  Turn around \n");

    for (int i = 0; i < n; i++) {
        total_wt += wait_time[i];
        total_tat += tat[i];
        printf("\n %4d\t  %4d\t  %4d\t %4d \n", i+1, burst_time[i], wait_time[i], tat[i]);
    }

    printf("\n Average waiting time = %4f \n", (float)total_wt / (float)n);
    printf("\n Average turn around time = %4f \n", (float)total_tat / (float)n);
}

int main() {
    int proc[100], n;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[100];

    for (int i = 0; i < n; i++) {
        printf("\n Enter the %d's process burst time: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    avgtime(proc, n, burst_time);
    return 0;
}
