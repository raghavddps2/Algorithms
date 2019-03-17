/*
This is just to clear some basics doubts with regards to pointers and swapping

*/
#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main(){
    int a = 10;
    int b = 20;
    swap(&a,&b);
    printf("%d %d",a,b);
}