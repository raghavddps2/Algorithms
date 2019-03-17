
/*
    @Author: Raghav Maheshwari
    @Date: 17th March, 2019
    @Topic: MergeSort

    Algorithm:
        1. Basically what we do is divide the array into half and half.
        2. We divide it until we obtain a single element
        3. We thenmerge the two arrays, using the merge sort function.
*/

#include<stdio.h>

void Merge(int *Left,int *Right,int nL,int nR,int *A){
    int i=0;
    int j=0;
    int k=0;
    while(i<nL && j<nR){
        if(Left[i]<=Right[j]){
            A[k] = Left[i];
            i++;
        }
        else{
            A[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i<nL){
        A[k] = Left[i];
        i++;
        k++;
    }

    while(j<nR){
        A[k] = Right[j];
        j++;
        k++;
    }
}
void MergeSort(int *A,int n){
    if(n<2){
        return;
    }
    int mid = n/2;
    int nL = mid;
    int nR = n-mid;
    int Left[nL];
    int Right[nR];
    
    for(int i=0;i<mid;i++){
        Left[i] = A[i];
    }
    for(int j=mid;j<n;j++){
        Right[j-mid] = A[j];
    }

    MergeSort(Left,nL);
    MergeSort(Right,nR);

    Merge(Left,Right,nL,nR,A);

}
void main(){
    int n;
    printf("\nEnter the number of elements in the array");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements of the array");

    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("\nSorting Starts...");
    MergeSort(A,n);
    printf("\nSorting ends...");

    printf("\nThe sorted elements are:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

/*
    --OUTPUT---
    Enter the number of elements in the array5

Enter the elements of the array5
4
3
2
1

Sorting Starts...
Sorting ends...
The sorted elements are:        1 2 3 4 5


*/