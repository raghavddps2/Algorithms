/*
@Author: Raghav Maheshwari.
@Date: 21/02/19
ALGORITHM FOR BINARY SEARCH.
Please note that, one of the very important condition of binary search is the array should be sorted.
-- The algorithm is as follows.

    1. Compare x with the middle element.
    2. If x matches with middle element, we return the mid index.
    3. Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element.
       So we recur for right half.
    4.Else (x is smaller) recur for the left half.
*/
#include<stdio.h>
#include<malloc.h>
#include <math.h>
#include <sys/time.h>
#include<stdlib.h>

int binarySearch(int a[],int low,int high,int key){
    if(high>=1){
        int mid;
        mid = low + ((high - low) / 2);
        // mid = low+high/2; This is an erro!!  it fails if the sum of low and high is greater 
        //than the maximum positive int value (2^31 – 1).
        // printf("%d",mid); For debi=ugging purpose.

        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key){
           return binarySearch(a,mid+1,high,key); //return the function only.
        }
        else{
           return binarySearch(a,low,mid-1,key);
        }
    }
    return -1;
}

void main(){
    printf("\n----------------------------------------------------\n");
    int *a;
    int key,pos,n,i;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    // printf("\nEnter the elements of the array:\t");
    for(i=0;i<n;i++){
        a[i] = i;
        // printf("%d ",a[i]); For debugging
    }

    printf("\n Enter the element you wanna find:\t");
    scanf("%d",&key);
    clock_t start = clock();
    pos = binarySearch(a,0,n-1,key);
    clock_t end = clock();

    printf("\nThe element is found at %d",pos);
    double time;
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nThe timetaken by the algorithms is %f",time);
    printf("\n----------------------------------------------------\n");
}