#include <unistd.h>
#include <stdio.h>
#define max 30

int main() {
    int i, n, t, bt[max], wt[max], tat[max], tem[max], at[max], p[max];
    float awt = 0, atat = 0;

    printf("Enter the number of process:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter burst time:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival time:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    
    tem[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // swap burst time
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                // swap process id
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

                // swap arrival time accordingly
                t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
        tem[i + 1] = tem[i] + bt[i];
        wt[i] = tem[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t %d\t %d\t %d\t %d\n", i + 1, bt[i], wt[i], tat[i], at[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("awt:%.2f\n", awt);
    printf("atat:%.2f\n", atat);

    return 0;
}