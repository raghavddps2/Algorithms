#include<stdio.h>
void Merge(int *left,int *right,int nL,int nR,int *A){
    int i=0,j=0,k=0;
    while(i<nL && j<nR){
        if(left[i]<=right[j]){
            A[k] = left[i];
            i++;
        }
        else{
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<nL){
        A[k] = left[i];
        i++;
        k++;
    }

    while(j<nR){
        A[k] = right[j];
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

    int left[nL];
    int right[nR];

    for(int i=0;i<mid;i++){
        left[i] = A[i];
    }    

    for(int i=mid;i<n;i++){
        right[i-mid] = A[i];
    }

    MergeSort(left,nL);
    MergeSort(right,nR);

    Merge(left,right,nL,nR,A);
}
void main(){
    int n;
    printf("\nEnter the number of elements");
    scanf("%d",&n);

    int A[n];
    printf("\nEnter the values of array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    MergeSort(A,n);
    printf("\nThe elements of the array are:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

//Time complexity: O(nlogn)
//Space complexity: O(n)