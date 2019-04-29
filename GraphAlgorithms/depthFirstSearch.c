/*
    @Author: Raghav Maheshwari
    @Date: 29th April, 2019
    @Topic: DepthFirstSearch Algorithm

    ALgorithm: Start from the elemnt and push the connecting elements into the stack and pop 
                to the visited array one by one. IN this way, we continue till all the elements are covered.
    Time complexity: O(V+E) Here, V is the number of vertices in the graph and E, the 
                     number of edges in the graph.
*/

#include<stdio.h>

int n; //No of nodes in the graph.
int arr[10][10]; //Declaring a two dimensional matrix for the adjacency matrix.
int visited[10] = {0}; //Making an array to mark whether the node is visited or not.

void dfs(int i){
    printf("%d",i);
    visited[i] = 1; //Printing whatever we get in the function and marking as visited.

    int j;
    for(int j=1;j<=n;j++){
        //If not visited and a path exits from i to j(Adjacency matrix wise.)
        if(visited[j] == 0 && arr[i][j] == 1){
            printf("->");
            dfs(j);
        }
    }
}
void main(){
    printf("\nEnter the number of nodes:\t");
    scanf("%d",&n);

    printf("\nENter the adjacency matrix:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dfs(1); //Starting with the first node.

}