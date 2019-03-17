#include<stdio.h>
void main(){
    int n1 = 19,i;
    int A[19] = {14, 5, 14, 34, 42, 63, 17, 25, 39, 61, 97, 55, 33, 96, 62, 32, 98, 77, 35};
    int ret[n1];
    int B =56;
    for (i = 0; i < n1-B; i++) ret[i] = A[i + B];
	for(int k=i;k<n1;k++) ret[k] = A[k-B-1];

    for(int i=0;i<n1;i++){
        printf("%d ",ret[i]);
    }
}