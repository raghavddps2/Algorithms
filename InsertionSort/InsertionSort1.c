/*
    @Author: Raghav Maheshwari
    @Date: 17th March, 2019
    @Topic: Insertion Sort


    Algorithm:
            Step 1: The first step is to Select the unsorted elemnet, we start from 1
            Step 2: Now we check will all elements with less index than the given element and swap if we found one greater
            Step 3: Finally when we are done all this we insert the key or the unsorted element back into the position
            Step 4: This makes the entire array sorted.

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InsertionSort(int *A,int n){
    int i,j;
    for(int i=1;i<n;i++){
        int key = A[i];
        j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int A[n];
    // printf("\nEnter the elements of the array");
    for(int i=0;i<n;i++){
        A[i] = rand()%1000;
    }

    clock_t start = clock();
    InsertionSort(A,n);
    clock_t end = clock();

    double time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken by the algorithm is %f",time);
}
/*
    ----OUTPUT-----
    X = [10000,20000,30000,40000,50000,60000,70000,80000,90000,100000]
    Y = [0.100000,0.358000,0.813000,1.461000,2.268000,3.297000,4.490000,5.987000,7.512000,9.535000]





*/