/*

    @Author: Raghav Maheshwari
    @Date: 29th April, 2019
    @Topic: Dijkstras Algorithm


    Algorithm: In this we start from the source vertex and marke the distance for neigbouring
                vertices. Then we start with the leats distance one and then mark the new distance if 
                it is less than the previous one. In this way we obtain the shortest path for all nodes from the
                source node.

    Time Complexity: O(n^2)
    Space Complexity: O(n)
*/
#include<stdio.h>
#define INFINITY 1000

int n,source; //For the number of nodes in the graph and the source node.
int cost[10][10]; //For the cost matrix.
int distance[10]; //For storing the distance from the source node.
int visited[10]; //FOr marking a node as visited and not visited.

int min_distance(){

    int min_value = INFINITY;
    int min_index;

    for(int i=0;i<n;i++){
        //Checks for all if not visited and the distnace[i] is less than the minimum value.
        if(!visited[i] && distance[i]<=min_value){
            min_value = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

 //This function prints the distance.
void printSolution(){
    printf("\nVertex distance from source");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t\t%d",i,distance[i]);
    }
    printf("\n");
}

void dijkstras(){

    for(int i=0;i<n;i++){
        distance[i] = INFINITY;
        visited[i] = 0;
    }
    distance[source] = 0;
    ///Number of edges is n-1 only.
    for(int i=0;i<n-1;i++){
        int min = min_distance();
        visited[min] = 1;

        for(int j=0;j<n;j++){
            //Should not be visited.
            //Should not be zero
            //Should not be infinity
            //distance[j] > distance[min]+cost[min][j];
            if(!visited[j] && cost[min][j] && distance[min] != INFINITY && 
                distance[j]>distance[min]+cost[min][j]){
                    distance[j] = distance[min] + cost[min][j];
                }
        }    
    }

    printSolution();

    
}

void main(){
    printf("\nEnter the number of nodes in the graph:\t");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("\nEnter the source node:\t");
    scanf("%d",&source);

    dijkstras();
}
/*
    Output:
Enter the number of nodes in the graph:	5

Enter the adjacency matrix:
    0 7 3 0 0 
    7 0 1 2 6
    3 1 0 2 0
    0 2 2 0 4
    0 2 0 4 0

Enter the source node:	0

Vertex distance from source
    0			0
    1			4
    2			3
    3			5   
    4			9

*/
