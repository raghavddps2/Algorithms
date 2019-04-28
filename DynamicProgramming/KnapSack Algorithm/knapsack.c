#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

void knapsack(int n,int *weight, int *profit, int capacity){
    //Create a table as we create on paper.
    int table[n+1][capacity+1];

    //Making the first row as 0, because there is no item selected.
    for(int i=0;i<=n;i++){
        table[i][0] = 0;
    }
    //Making the first column as 0, as the capacity of the knapsack is zero.
    for(int j=0;j<=capacity;j++){
        table[0][j] = 0;
    }

    /*
        So, basically we start from row 1 and for each row, we iterate over whole cap.
        If we find the weight of the ith object as lesser than or equal to the then cap, 
        we change it whatever is max between 
            -- table[i-1][c] or table[i-1][c-weight[i]] + profit[i];

        else 
            we assign it as table[i-1][c];

    */
    for(int i=1;i<=n;i++){
        for(int c=1;c<=capacity;c++){
            if(weight[i] <= c){
                table[i][c] = max(table[i-1][c],(table[i-1][c-weight[i]]+profit[i]));
            }
            else{
                table[i][c] = table[i-1][c];
            }
        }
    }
    //So, this will fill up our entire table.
    
    int selected[n]; ///We created this array to know as to what all elements are included. We will make as 1, if element is included otherwise remain as 0
    int netCap = capacity; 
    for(int i=n;i>=1 && netCap != 0;i--){

        //If the table[i-1][c] and table[i][c] are same, we will not inlcude that.
        //If not same, we will mark selected for that item as 1, and reduce the netCap by weight[i]
        if(table[i][netCap] != table[i-1][netCap]){
            selected[i] = 1;
            netCap -= weight[i];
        }
        else{
            selected[i] = 0;
        }
    }   
    int maxprofit = 0;
    printf("\n-----------------------------------------------------------\n");
    printf("\nThe items that are taken are:\t");
    for(int i=1;i<=n;i++){
        if(selected[i]){
            printf("%d ");
            maxprofit += profit[i];
        }
    }
    printf("\nThe maximum profit that can be obtained is %d",maxprofit);
    printf("\n------------------------------------------------------------\n");
}

void main(){
    int n;
    printf("\nEnter the number of items:\t");
    scanf("%d",&n);

    int weight[n+1],profit[n+1],capacity;
    for(int i=1;i<=n;i++){
        printf("\nEnter the weight and value of item %d:\t",i);
        scanf("%d",&weight[i]);
        scanf("%d",&profit[i]);
    }
    printf("\nEnter the capacity of the knapscak:\t");
    scanf("%d",&capacity);

    knapsack(n,weight,profit,capacity);
}