#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, t = 0, completed = 0, min_index;
    int bt[MAX], p[MAX], pro[MAX];
    int rt[MAX], wt[MAX], tat[MAX];
    int is_completed[MAX] = {0};
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pro[i] = i + 1;
    }

    printf("Enter the burst time and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &bt[i], &p[i]);
        rt[i] = bt[i];  
    }

    
    int arrival_time[MAX];
    for (i = 0; i < n; i++) {
        arrival_time[i] = 0;
    }

    while (completed != n) {
        int highest_priority = INF;
        min_index = -1;

        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= t && !is_completed[i]) {
                if (p[i] < highest_priority && rt[i] > 0) {
                    highest_priority = p[i];
                    min_index = i;
                }
                
                else if (p[i] == highest_priority && rt[i] > 0) {
                    if (arrival_time[i] < arrival_time[min_index]) {
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1) {
            t++;  
            continue;
        }


        rt[min_index]--;
        t++;

        if (rt[min_index] == 0) {
            completed++;
            is_completed[min_index] = 1;
            int finish_time = t;
            tat[min_index] = finish_time - arrival_time[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            awt += wt[min_index];
            atat += tat[min_index];
        }
    }

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pro[i], bt[i], p[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f\n", awt / n);
    printf("Average turnaround time: %.2f\n", atat / n);

    return 0;
}
