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



void heapify(int *arr,int n,int i){
    int largest = i; //Setting the node element
    int leftChild = 2*i; //setting the left child
    int rightChild = (2*i) + 1; //setting the right child


    //If l<n and the left child is greater than the node, then we relace largest by the leftCHild and swap later
    if(leftChild<n && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }

    //If r<n and right child is greater than the node, then we replace largest by the right child and swap later.
    if(rightChild < n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    //If both the node index we had initially and the largest value index are not equal, we swap the both, and call heapify on the reaming subtree.
    if(largest != i){
        int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
        heapify(arr,n,largest);
    }
}
void main(){
    int n; //Variable for number of elements in the array
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int arr[n]; //array to store the elements.

    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }

    //Building the Max-Heap, we start fron n/2 because we dont wanna include the leaf nodes.
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    printf("\nElements heapified!");

    for(int i=n;i>=1;i--){
        //THe largest element comes at the first, so we shift it at the last, and the last element comes to first.
        int temp = arr[i];
            arr[i] = arr[1];
            arr[1] = temp;
        //Heapify root element to get the highest element at the root again!
        heapify(arr,i,1);
        //We give the root index only (0)
    }

    printf("\nThe sorrted array is:\t");
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }


}