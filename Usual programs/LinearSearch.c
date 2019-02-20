#include<stdio.h>
#include<malloc.h>
#include <sys/types.h>
#include <sys/time.h>
#include<stdlib.h>

int LinearSearch(int *a,int key,int n){

    for(int i=0;i<n;i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

void main(){
    printf("\n----------------------------------------------------\n");
    printf("\nEnter the number of elements in the array:\t");
    int n;
    scanf("%d",&n);

    int *a;
    int key,pos;
    a = (int *)malloc(n*sizeof(int));

    // printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        a[i] = rand();
    }  
    clock_t start = clock();
    pos = LinearSearch(a,a[0],n);
    clock_t end = clock();

    printf("\nThe element is found at %d",pos);
    double time;
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nThe timetaken by the algorithms is %f",time);
    printf("\n----------------------------------------------------\n");
}
/*
    This s to be noted that, linear search is rarely used because the time complexity of this algorithm comes out to be O(n),
    which is greater than Binary search and other searches. For ex, considering a proper binary search tree, it will do in
    approximatelyy O(log n) times.
*/