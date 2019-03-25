/*
    @Author: Raghav Maheshwari
    @Date: 26th March, 2019
    @Topic: Knapsack problem!
*/

#include<stdio.h>


//Creating a structure for storing the weight and value pair.
struct item{
    float value; //This is same as profit.
    float weight;
    float ppw;
};
int n;
struct item arr[1000]; 
//Defining the sorting function in reverse order (Descending order.)
void sort(struct item A[],int n){

    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j].ppw<A[j+1].ppw){
                struct item temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
void main(){
    int capacity;
    printf("\nEnter the number of objects you have:\t");
    scanf("%d",&n); //Taking the number of objects.

     //Creating an array of structures.


    //Taking the weight and value of all the n objects.
    for(int i=0;i<n;i++){
        // printf("\nEnter the value of object %d:\t",i);
        scanf("%f",&arr[i].value);

        
        // printf("\nEnter the weight of object %d:\t",i);
        scanf("%f",&arr[i].weight);
    }

    //Taking the capacity of the knapsack
    printf("\nEnter the capacity of knapsack:\t");
    scanf("%d",&capacity); 

    /*Follows the solution for the problem: 
        
        --The best approach in this case is to take the profit/weight for each object.
        -- Then following the maximum to lower, we will get the maximum profit and verify the constraint of capacity of knapsack.
    */
    //Creating an array to store profit per weight for all objects.
   for(int i=0;i<n;i++){
       arr[i].ppw = arr[i].value/arr[i].weight;
   }
   //Now we need to sort the array obtained in decreasing order.
    
    sort(arr,n);
    
    
    //Now, we should get the fraction matrix to get the fraction of each object present to optimize the profit 
    //in the constraint given.

    int cap = capacity;
    int i=0;
    float frac[n];
    printf("\n");
    // for(int i=0;i<n;i++){
    //     printf("%f %f %f\n",arr[i].ppw,arr[i].weight,arr[i].value);
    // }

    //Getting the fraction for each!
    while(cap > 0 && i<n){
        
        if(arr[i].weight > cap){
            
            frac[i] = (float)cap/arr[i].weight;
        }
        else{
            frac[i] = 1;
        }
        cap = cap - arr[i].weight;
        i++;
    }
    //    for(int i=0;i<n;i++){
    //     printf("\n%f",frac[i]);
        
    // }
    
    // This will give the optimal price.
    float optimalProfit = 0;
    for(int i=0;i<n;i++){
        optimalProfit += frac[i]*arr[i].value;
    }
    printf("\n---------------------------------------------------\n");
    printf("\nThe optimal profit comes out to be %f",optimalProfit);
    printf("\n---------------------------------------------------\n");
}

/*
    ---------------------------OUTPUT---------------------------
        Enter the number of objects you have:   3
            60
            10
            100
            20
            120
            30

            Enter the capacity of knapsack: 50

            6.000000 10.000000 60.000000
            5.000000 20.000000 100.000000
            4.000000 30.000000 120.000000

            1.000000
            1.000000
            0.666667
            ---------------------------------------------------

            The optimal profit comes out to be 240.000000
            ---------------------------------------------------
*/