#include<stdio.h>
#include<conio.h>

void main(){
    int a = 10;
    int b = 20;
    int c = 30;

    a = c;
    b = c;

    printf("%d %d %d ",a,b,c);
}