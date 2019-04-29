/*
    @Author: Raghav Maheshwari
    @Date: 28th April, 2019
    @Problem: Floyds Algorithm

    //Basically, we have the distances and we upadte the min(arr[i][j],(arr[i][k],arr[k][j]));
    Time complexity: O(n^3)
    Space Complexity: O(1) //If no matrix is created.
                      O(n^2) //Otherwise.

    //this is basically the All-Pairs shortest path problem.
*/


#include<stdio.h>


void floyd(int n,int arr[n][n]){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>(arr[i][k]+arr[k][j])){
                    arr[i][j] = (arr[i][k]+arr[k][j]);
                }

                //Assigns if less than the direct path.
            }
        }
    }
}
void main(){
    int n;
    printf("\nEnter the no of vertices in the graph:\t");
    scanf("%d",&n);

    int arr[n][n];

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    floyd(n,arr);

    printf("The result for the shortest path matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}