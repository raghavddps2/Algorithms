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
void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int A[n];
    printf("\nEnter the number of elements in the array");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("\nSorting Begins...");
    for(int i=1;i<n;i++){
       int Key = A[i];
       int j=i-1;
        while(j>=0 && A[j]>Key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = Key;
    }
    printf("\nSorting Ends...");

    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

/*
    ------OUTPUT-----
    Enter the number of elements in the array:
10

Enter the number of elements in the array 45
47
78
89
56
85
24
12
456
78

Sorting Begins...
Sorting Ends...
The sorted array is:    12 24 45 47 56 78 78 85 89 456



*/