/*

    @Author: Raghav Maheshwari
    @Date: 29th April, 2019
    @Topic: Kruskals Allgorithm

    Algorithm:
        Start with the least, and keep on looking for the least weighted edge till all the nodes are completed.
        THis way the MST is determined. Print the edges and the weight of MST.

        Time complexity: O(nE) but O(n^3) here. ;How?
        Space complexity: O(n).

*/


#include<stdio.h>
int n; //FOr the number of vertices in the graph.
int arr[10][10];//A 2-Dimensional matrix which will have the cost of the paths, to be given by
                    //by the user.
void kruskals(){
    int a; //This is for the starting vertex in an edge of MST
    int b; //This is for the ending vertex in an edge of MST
    int min_cost = 0; //This defines the minimun cost of the MST formed.
    int u, v; //Two variables for knowing the status of the parent array.

    int parent[n]; //THis keeps track whether the node is visited or not.

    //Initializing all to zero
    for(int i=1;i<=n;i++){
        parent[i] = 0;
    }

    int numberOfEdges = 1;

    //We have taken number of edged less than n because, for a MInimum spanning tree, for 
    // a graph with n vertices the edges should be n-1.
    while(numberOfEdges < n){
        int min = 111;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]<min){
                    min = arr[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        while(parent[u]){
            u = parent[u];
        }
        while(parent[v]){
            v = parent[v];
        }

        /*
            THe above two loops are nothing, they just check if the node is visited, and change the 
            value of u and v accordingly.
        */
       if(u != v){
           printf("\nEdge %d: %d---------------->%d, cost: %d",numberOfEdges++,a,b,min);
           parent[v] = u; //THis sets the node as visited.
           min_cost += min;
       }

       //NOw, we will set the done ones to max again, considering undirected graph(111)
       arr[a][b] = arr[b][a] = 111;
    }

    printf("\n----------------------------------------------------------\n");
    printf("\nThe minimum cost of the mimimum spanning tree is %d",min_cost);
    printf("\n----------------------------------------------------------\n");
}

void main(){
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    printf("Enter the elements of the matrix:\n Write 111 for Infinity:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    //Now, calling the kruskals method to find the minimum spanning tree.
    kruskals();

}
/*
    Sample Input:  

    0 1 3 4 
    1 0 2 111
    3 2 0 5
    4 111 5 0
*/
/*
    Sample Output

        Edge 1: 1---------------->2, cost: 1
        Edge 2: 2---------------->3, cost: 2
        Edge 3: 1---------------->4, cost: 4
    ----------------------------------------------------------
        The minimum cost of the mimimum spanning tree is 7
    ----------------------------------------------------------

*/