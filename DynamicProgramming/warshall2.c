#include<stdio.h>

void warshall(int n,int arr[n][n]){
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

    warshall(n,arr);

    printf("The transitive closure is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    

}