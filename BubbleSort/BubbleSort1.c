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
#include<stdlib.h>
#include<time.h>
void main(){
    printf("\nEnter the number of elements in the array:\t");
    int n;
    scanf("%d",&n);
    int A[n];
    int i,j;

    
    for(int i=0;i<n;i++){
        A[i] = rand()%1000; //This will randomly assign the values to the array
    }
    printf("\nSorting begins....");
    clock_t start = clock(); //Starting the clock here.
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
    clock_t end = clock(); //Ending the clock here.
    double time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nThe time taken by the algorithm is %f",time);

    

    // printf("\nThe sorted arrray is:\t");
    // for(i=0;i<n;i++){
    //     printf("%d ",A[i]);
    // }

    //Not printing the above llines of code as now we are just interested in the time complexity!
}
/*
    --------------------OUTPUT--------------------
    Input Size:                        Time taken

    10000                               0.469000
    20000                               1.372000
    30000                               3.720000
    40000                               5.884000
    50000                               9.968000
    60000                               14.127000
    70000                               19.341000
    80000                               24.844000
    90000                               35.700000
    100000                              43.224000
*/