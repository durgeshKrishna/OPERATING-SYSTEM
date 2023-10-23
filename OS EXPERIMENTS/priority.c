#include <stdio.h>

void main() {
    int n, i, max = 0, k = 0;
    float avg_wait = 0, avg_trip = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], wait[n], burst_time[n], arrival_time[n], trip_time[n], p_sort[n], temp[n];

    for (i = 0; i < n; i++) {
        printf("Enter the process ID for process %d: ", i + 1);
        scanf("%d", &p[i]);

        printf("Enter the priority for process %d: ", p[i]);
        scanf("%d", &temp[i]);

        printf("Enter the burst time for process %d: ", p[i]);
        scanf("%d", &burst_time[i]);

        printf("Enter the arrival time for process %d: ", p[i]);
        scanf("%d", &arrival_time[i]);
    }

    // Find max priority
    for (i = 0; i < n; i++) {
        if (temp[i] > max)
            max = temp[i];
    }

    // Priority sorting
    while (max > 0) {
        for (i = 0; i < n; i++) {
            if (max == temp[i]) {
                p_sort[k] = i;
                k++;
            }
        }
        max--;
    }

    wait[0] = 0;

    for (i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst_time[p_sort[i - 1]] - arrival_time[p_sort[i - 1]];
        if (wait[i] < 0)
            wait[i] = 0;
    }

    for (i = 0; i < n; i++) {
        avg_wait += wait[i];
    }

    avg_wait = (float)avg_wait / n;

    for (i = 0; i < n; i++) {
        trip_time[i] = wait[i] + burst_time[p_sort[i]];
    }

    for (i = 0; i < n; i++) {
        avg_trip += trip_time[i];
    }

    avg_trip = (float)avg_trip / n;

    printf("\nBefore scheduling\n");
    printf("Sno\tProcess ID\tPriority\tArrival Time\tBurst Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i], temp[i], arrival_time[i], burst_time[i]);
    }

    printf("\nAfter scheduling\n");
    printf("Sno\tProcess ID\tPriority\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[p_sort[i]], temp[p_sort[i]], arrival_time[p_sort[i]], burst_time[p_sort[i]], wait[i], trip_time[i]);
    }

    printf("\nThe average wait time is %.4f\n", avg_wait);
    printf("The average turnaround time is %.4f\n", avg_trip);
}
