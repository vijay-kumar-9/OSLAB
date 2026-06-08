#include<stdio.h>
int main() {
    int n, i, tq, time = 0, remain;
    int bt[10], rt[10], wt[10], tat[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time = time + rt[i];
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    remain--;
                }
                else {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
            }
        }
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    return 0;
}