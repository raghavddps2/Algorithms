/*

    @Author: Raghav Maheshwari
    @Date: 29th April, 2019
    @Topic: Prims Algorithm

    Algorithm:
        In this we start with the source node we have, then we look for the min, then 
        we go on for all the connecting minimums, and finallly we get the MInimum spanning tree.

    Time Complexity: O(vE) = O(n^2) ;How?
    Space Complexity: O(n)

*/
#include<stdio.h>

int n; //THis tells the number of vertices in the graph
int arr[10][10]; //This makes an array of 10X10 
int visited[10] = {0}; //This is used to keep track of visited nodes.


void prims(){

    int a,b; //These are basically the source and dest for an edge.
    int u,v; //These both are used to keep track of visited nodes.

    int ne = 1; //This is for the number of edges in the MST.

    int min_cost = 0 ;//INitializing the min_cost of the spanning tree.

    while(ne < n){
        int min = 111;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //Follow only if this is visited.
                if(arr[i][j]<min && (visited[i] != 0)){
                    min = arr[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        //FOllow this if any of the source/dest is not visited.
        if((visited[u] == 0) || (visited[v] == 0)){
            printf("\nEdge %d: %d--------------------->%d, cost:%d",ne++,a,b,min);
            visited[b] = 1;
            min_cost += min;
        }
        arr[a][b] = arr[b][a] = 111;
    }
    printf("\n------------------------------------------------------");
    printf("\n The cost of the MInimum spanning tree is %d",min_cost);
    printf("\n------------------------------------------------------\n");
}
void main(){
    
    int source; //This defines the source node for traversing the graph.
    
    printf("\nEnter the number of vertices in the graph:\t");
    scanf("%d",&n);

    printf("\nEnter the cost values for the path.");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0){
                arr[i][j] = 111;
            }
        }
    }

    //Actually, no need to ask the source node as well, just put
    //visited[1] = 1;
    //This is because anyways the MST would be same!
    printf("\nEnter the source node:\t");
    scanf("%d",&source);

    visited[source] = 1;

    prims(); //Calling the function, it will form the MST.
}

/*

Sample Input:
        
    Enter the number of vertices in the graph:	4

    Enter the cost values for the path.
        0 1 3 4 
        1 0 2 0
        3 2 0 5
        4 0 5 0

    Enter the source node:	3

Sample Output:
    Edge 1: 3--------------------->2, cost:2
    Edge 2: 2--------------------->1, cost:1
    Edge 3: 1--------------------->4, cost:4
------------------------------------------------------
    The cost of the MInimum spanning tree is 7
------------------------------------------------------

*/