#include<stdio.h>

//Structure defined for the same.
struct job{
    char jobId;
    int profit;
    int deadline;
};
//Usual Sorting function (Choose a stable sorting algorithm)
void sort(struct job jobs[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(jobs[j].profit<jobs[j+1].profit){
                struct job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}
void main(){
    int n;
    printf("\nEnter the number of jobs:\t");
    scanf("%d",&n);
    struct job jobs[n];

    
    for(int i=0;i<n;i++){

        // printf("\nEnter the job ID for job %d:\t",i+1);
        scanf(" %c",&jobs[i].jobId);


        // printf("\nEnter the profit for job %d:\t",i+1);
        scanf("%d",&jobs[i].profit);


        // printf("\nEnter the deadline for job %d:\t",i+1);
        scanf("%d",&jobs[i].deadline);
    }
    int max = jobs[0].deadline;
    for(int i=0;i<n;i++){
        if(jobs[i].deadline>max){
            max = jobs[i].deadline;
        }
    }
    // printf("\n----------------------\n");
    // for(int i=0;i<n;i++){
    //     printf("\n %c %d %d",jobs[i].jobId,jobs[i].profit,jobs[i].deadline);
    // }
    int time = max;
    sort(jobs,n);
    char arr[max];
    for(int i=0;i<max;i++){
        arr[i] = '\0';
    }

    //Main logic part for the entire problem.
    for(int i=0;i<n;i++){
        int k = jobs[i].deadline-1;
        if(time != 0){
            while(arr[k] != '\0' && k>-1){
                k--;
            }
            if(k>=0){
                arr[k] = jobs[i].jobId;
                time--;
            }
        }
        else{
            break;
        }
        
    }
    printf("\nThe job sequence is:\t");
    for(int i=0;i<max;i++){
        printf("%c ",arr[i]);
    }
}
/*
    a
35
3
b
30
4
c
25
4
d
20
2
e
15
3
f
12
1
g
5
2

*/