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

void warshall(int n,int arr[n][n]){
    //Logic for warshalls. 
    //Either a direct path or (a connecting path (&& both should be one))
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
    printf("\n Enter the size of the matrix:\t");
    scanf("%d",&n);

    int arr[n][n];

    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    warshall(n,arr); //Calling the function

    printf("The transitive closure is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    

}