/*
    @Author: Raghav Maheshwari.
    @Ques Number: Problem 1 (Algo Basics);
*/
#include<stdio.h>
#include<time.h>

void GCD(int m,int n){
    while(m!=n){
        if(m>n){
            m = m-n;
        }
        else{
            n = n-m;
        }
    }
}

int main(){
    int a,b;
    printf("\n-----------------------------------------------------\n");
    printf("\nEnter the two numbers whose GCD You wanna calculate:\t");
    scanf("%d%d",&a,&b);

    clock_t t;
    t = clock();
    GCD(a,b);
    t = clock() - t;
    double time  = ((double)t)/CLOCKS_PER_SEC;
    printf("It took %d clicks and The time taken is %f seconds",t,time);
    printf("\n-----------------------------------------------------\n");
    //printf("\nThe GCD of %d and %d is %d",a,b,Gcd);
}
/*
 * Observation:-
 * 
 *      X           Y           Time
 *      
 *    
 * 
 * 
 */