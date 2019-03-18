#include<stdio.h>

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
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int A[n];
    printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    QuickSort(A,0,n-1);

    printf("\nThe elements of the array are:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

//Time Complexity:(Best/Avergae case): O(nlogn)
//Time Complexity: Worst Case O(n^2)
//Space Complexity: O(log n).

