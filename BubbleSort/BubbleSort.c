/*

@Author: Raghav Maheshwari
@Date: 17th March, 2019
@Topic: Bubble Sort Algorithm


Algorithm:
    Step 1: We will iterate over the wjole array for n-2 times.
    Step 2: During each pass, we will send the largest element at the end.
    Step 3: In the case, if the A[j]>A[j+1], we will swap it and till the end of the inner loop, it will be at the last.
    Step 4: Following this, we will reach the end of the sorted array. We can print the array them.
*/
#include<stdio.h>
void main(){
    printf("\nEnter the number of elements in the array:\t");
    int n;
    scanf("%d",&n);
    int A[n];
    int i,j;

    printf("\nEnter the elements of the array\t");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("\nSorting begins....");

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("\nSorting Ends...");

    printf("\nThe sorted arrray is:\t");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
/*
    --------------------OUTPUT--------------------
    Enter the number of elements in the array:      10

    Enter the elements of the array 58 45 56 74 12 0 45 18 23 54

    Sorting begins....
    Sorting Ends...
    The sorted arrray is:   0 12 18 23 45 45 54 56 58 74
*/