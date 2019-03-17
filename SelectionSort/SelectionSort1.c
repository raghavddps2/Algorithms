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
#include<time.h>
#include<stdlib.h>

void SelectionSort(int *A,int n){
    printf("\nSorting Begins......");
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
    printf("\nSorting Ends...");
}
void main(){
    int n;
    printf("\nEnter the no of elements in the array:\t");
    scanf("%d",&n);
    int A[n];

    for(int i=0;i<n;i++){
        A[i] = rand()%1000;
    }

    clock_t start = clock(); //Start the clock
    SelectionSort(A,n);   //Calling the selection sort function
    clock_t end = clock(); ///End the clock

    double time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken by the algorithm is %f",time);
}

/*
    ----OUTPUT-----
    Input Size:                   
    X= [10000,20000,30000,40000,50000,60000,70000,80000,90000,100000];
    Time:
    Y=[0.124000,0.431000,0.949000,1.711000,2.616000,3.811000,5.131000,6.688000,8.572000,10.735000]

    //The plot is made using the python file SelectionSort1Plot.py !!
*/