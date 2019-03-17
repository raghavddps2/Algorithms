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
#include<stdlib.h>
#include<time.h>

/*
    This is actually the main part of the program, this will Merge the two arrays, and hence we can obtain
    the values in sorted order.

*/
void Merge(int *Left,int *Right,int nL,int nR,int *A){
    int i=0,j=0,k=0;
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


/*
    The MergeSort function basically did=vides the array until we achieve 1 element in each division.
    Affter ths is done it calls the Merge function to mwerge the arrays created.
*/
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
    for(int i=mid;i<n;i++){
        Right[i-mid] = A[i];
    }

    MergeSort(Left,nL);
    MergeSort(Right,nR);

    Merge(Left,Right,nL,nR,A);
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int A[n];
    for(int i=0;i<n;i++){
        A[i] = rand()%1000;
    }
    printf("\nSorting Begins...");
    clock_t start = clock();
    MergeSort(A,n);
    clock_t end = clock();
    printf("\nSorting ends...");


    double time =  ((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken for the Algorithm to execute is %f",time);
}

/*
    ----OUTPUT----
    X = [10000,20000,30000,40000,50000,60000,70000,80000,90000,100000]
    Y = [0.015000,0.005000,0.022000,0.015000,0.013000,0.029000,0.016000,0.034000,0.027000,.022000];

    Time Complexity : O(nLogn);
    Space Complexity: O(n);
*/


