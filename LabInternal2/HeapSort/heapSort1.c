/*
    @Author: Raghav Maheshwari
    @Date: 29th April, 2019
    @Topic: Heap Sort

    ALgorithm: Form the max heap every time, put the node or root element at the last, and the last
                element at the first, heapify again(heapify(arr,i,0)) and again repeat the same thing.

    Time Complexity: O(nLogn)
    Space Complexity: O(1);
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
    int temp = *a;
        *a = *b;
        *b = temp;
}

void heapify(int *arr,int n,int i){
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }

    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }
    
    if(largest != i){
        swap(arr+i,arr+largest);
        // int temp = arr[largest];
        //     arr[largest] = arr[i];
        //     arr[i] = temp;
        heapify(arr,n,largest);
    }
}

void main(){
    int n; 
    printf("\nENter the number of elements:\t");
    scanf("%d",&n);

    int arr[n];
    for(int i=1;i<=n;i++){
        // scanf("%d",&arr[i]);
        arr[i] = rand()%1000;
    }

    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    clock_t start = clock();
    for(int i=n;i>=1;i--){
        swap(arr+i,arr+1);
        // int temp = arr[1];
        //     arr[1] = arr[i];
        //     arr[i] = temp;
        heapify(arr,i,1);
    }
    clock_t end = clock();
    double time = (double)((double)(end-start)/CLOCKS_PER_SEC);
    // printf("\nThe sorted elements are:\t");
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n----------------------------------------------------\n");
    printf("\nThe time taken by the Heap Sort is %lf",time);
    printf("\n----------------------------------------------------\n");
}