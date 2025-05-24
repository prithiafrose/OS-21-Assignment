#include <stdio.h>
#define MAX 30
#define INF 9999

int main() {
    int n, i, j, completed = 0, t = 0, min_index;
    int p[MAX], bt[MAX], at[MAX], rt[MAX];
    int wt[MAX], tat[MAX];
    int is_completed[MAX] = {0};
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  
    }

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    
    while (completed != n) {
        min_index = -1;
        int min_rt = INF;

        
        for (i = 0; i < n; i++) {
            if (at[i] <= t && !is_completed[i] && rt[i] < min_rt && rt[i] > 0) {
                min_rt = rt[i];
                min_index = i;
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
            tat[min_index] = finish_time - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            awt += wt[min_index];
            atat += tat[min_index];
        }
    }

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;
    printf("Average waiting time: %.2f\n", awt);
    printf("Average turnaround time: %.2f\n", atat);

    return 0;
}
