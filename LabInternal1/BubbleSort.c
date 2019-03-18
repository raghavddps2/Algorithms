#include<stdio.h>


//Basically, at every pass, the largest element is shifted to the last(Appropriate position).
void main(){
    int n;
    printf("\n Enter the value of n:\t");
    scanf("%d",&n);

    int A[n];

    printf("\nEnter the value of elements");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

}
//Best case time complexity: O(n) //When the data is already sorted.
// Worst/Average Time complexity: O(n^2);
//Space Complexity: O(1)