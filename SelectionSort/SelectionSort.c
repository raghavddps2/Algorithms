/*
    @Author: Raghav Maheshwari
    @Date: 17th March, 2019
    @Topic: Selection Sort Algorithm

    Algotithm:
        1. Start the count from the start, and initialize the min_index
        2. Then loop through the array and find the min value
        3. Then, swap the a[i] and a[min_index]
*/

#include<stdio.h>
void main(){
    int n;
    printf("\n Enter the number of elements:\t");
    scanf("%d",&n); 
    int A[n];

    printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("\n Sorting Begins...");

    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min_index]){
                min_index = j;
            }
        }
        int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
    }
    printf("\n Sorting End...");

    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }


}

/*
    -------OUTPUT-------
    Enter the number of elements:  10
    Enter the elements of the array:        78 45 23 45 56 89 45 12 45 47
    Sorting Begins...
    Sorting End...
    The sorted array is:    12 23 45 45 45 45 47 56 78 89
*/