#include<stdio.h.>
#define MAX 100
#define INF 9999
int main(){
    int cost[MAX][MAX],dist[MAX][MAX],n,i,j,k;
printf("enter no of nodes:");
scanf("%d",&n);
printf("enter cost matrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
            dist[i][j]=INF;
        else
            dist[i][j]=cost[i][j];
    }
}
for(k=0;k<n;k++){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dist[i][j]>dist[i][k]+dist[k][j])
                dist[i][j]=dist[i][k]+dist[k][j];
        }
    }
}
printf("\nShortest path matrix:\n");
for(i=0;i<n;i++){
    printf("\n for node %d:",i);
    for(j=0;j<n;j++){
        printf("to %d->%d\n",j,dist[i][j]);
    }
}
return 0;
}
