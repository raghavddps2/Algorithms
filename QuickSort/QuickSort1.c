/*
    @Author: Raghav Maheshwari
    @Date: 17th March, 2019
    @Topic: QuickSort

    Algortithm:
        Step1: The first step is to get the partitionIndex, as to where we have to partition the array.
        Step2: We get the partitionIndex, by assuming the pivot element as the last one and then shifting elements less too left
                and remaining to right.
        Step3: The element at the partition index goes at the last
        Step4: We retrun the partition Index, and then we split the array into two and sort the remianing elements.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp = *a;
        *a = *b;
        *b = temp;
}
int partition(int *A,int start,int end){
    int pivot = A[end];
     int partitionIndex = start;

    for(int i=start;i<=end-1;i++){
        if(A[i]<pivot){
            swap(&A[i],&A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex],&A[end]);
    return partitionIndex;
}
void QuickSort(int *A,int start,int end){
    if(start<=end){
        int partitionIndex = partition(A,start,end);
            QuickSort(A,start,partitionIndex-1);
            QuickSort(A,partitionIndex+1,end);
    }
}
void main(){
    int n;
    printf("\nEnter the value of n:\t");
    scanf("%d",&n);

    int A[n];
    for(int i=0;i<n;i++){
        A[i] = rand()%1000;

    }
    printf("\nSorting starts...");
    clock_t start = clock();
    QuickSort(A,0,n-1);
    clock_t end = clock();
    printf("\nSorting ends...");
    // for(int i=0;i<n;i++){
    //     printf("%d ",A[i]);

    // }
    double time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nThe time taken by the algorithm is %f",time);
}
/*
    ------OUTPUT---------
    X = [100000,200000,300000,400000,500000];
    Y = [0.033000,0.097000,0.205000,0.323000,0.501000,]



*/