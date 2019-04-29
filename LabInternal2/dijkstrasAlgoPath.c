#include<stdio.h>
#define INFINITY 1000
int n;
int cost[10][10];
int distance[10];
int parent[10];
int visited[10];
int source;

void printPath(int j){
    if(parent[j] == -1){
        return;
    }
    printPath(parent[j]);
    printf("->");
    printf("%d",j);
}

void printSol(){
    for(int i=0;i<n;i++){
        printf("\n%d\t\t\t%d\t\t\t%d",i,distance[i],source);
        printPath(i);
    }
    printf("\n");
}

int min_distance(){
    int min_value = INFINITY;
    int min_index;

    for(int i=0;i<n;i++){
        if(!visited[i] && distance[i]<=min_value){
            min_value = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstras(){

    

    for(int i=0;i<n;i++){
        parent[0] = -1;
        distance[i] = INFINITY;
        visited[i] = 0;
    }
    distance[source] =0;
    for(int i=0;i<n-1;i++){
        int min = min_distance();
        visited[min] = 1;

        for(int j=0;j<n;j++){
            if(!visited[j] && cost[min][j] && distance[min] != INFINITY && distance[j] > distance[min]+cost[min][j]){
                distance[j] = distance[min]+cost[min][j];
                parent[j] = min;
            }
        }
    }
    printSol();
}


void main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    
    scanf("%d",&source);
    dijkstras();
}