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
void swap(int *a,int *b){
    int temp = *b;
        *b = *a;
        *a = temp; 
}
int partition(int *A,int start,int end){
    int pivot = A[end];
    int partitionIndex = start;

    for(int i=start;i<=end-1;i++){
        if(A[i]<=pivot){
            swap(&A[i],&A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex],&A[end]);
    return partitionIndex;
}
void QuickSort(int *A,int start,int end){
    if(start<end){
        int partitionIndex = partition(A,start,end);
        QuickSort(A,0,partitionIndex-1);
        QuickSort(A,partitionIndex+1,end);
    }
    else{
        return;
    }
}
void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int A[n];
    printf("\nEnter the elements of the array");
    for(int i=0;i<n;i++){
        A[i] = rand()%1000;
    }
    printf("\nSorting Begins...");
    QuickSort(A,0,n-1);
    printf("\nSorting Ends...");
    printf("\nThe elements of the array are:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}