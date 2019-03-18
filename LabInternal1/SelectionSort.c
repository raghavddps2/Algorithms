#include<stdio.h>
//Basically, at every iteration of outer loop, the samllest element comes at the first(Appropriately).
void main(){
    int n;
    printf("Enter the value of n:\t");
    scanf("%d",&n);

    int A[n];
    printf("\nEnter the elemnets of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    //Sorting function begins...
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min_index]){
                min_index = j;
            }
        }
        int temp = A[min_index];
            A[min_index] = A[i];
            A[i] = temp;
    }

    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}