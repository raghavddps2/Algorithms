/*
    @Author: Raghav Maheshwari
    @Date: 28th April, 2019
    @Problem: Warshall Algorithm (Greedy Approach)

    1 represents a path present whereas 0 represents there is no path present.
    Time complexity: O(n^3)
    Space Complexity: O(1) //If no new array is created
                      O(n^2) //If a new array is created.
*/
#include<stdio.h>
int arr[10][10] = {0};

//Logic for warshalls. 
//Either a direct path or (a connecting path (&& both should be one))
void warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
}
void main(){
    int n;
    printf("\nEnter the number of vertices in the graph:\t");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    warshall(n); //Just calling the function.

    printf("The transitive closure of the matrix is :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
