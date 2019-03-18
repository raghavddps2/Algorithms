/**
 * @Author: Raghav Maheshwari
 * @Date: 19th March, 2019
 * @Topic: Reachable nodes from a given node.
 * 
 * 
 * 
 * Algorithm:
 *          Step1: In this we take the number of vertices and the Adjacency matrix and the starting node\
 *          Step2: We mark all the nodes as not visited initially.
 *          Step3: Then we call the bfs function on the given node and store all its connected vertices using snippet1
 *          Step4: Now, till f<=r, we mark the vertices as visited and then call bfs recursively on other elements to which 
 *                 the users input was connected. (This is to be seen in snippet 2);
*/
#include<stdio.h>

int q[20],visited[20],a[20][20],i,j,r=-1,f=0,n;

void bfs(int v){

    //Referred as snippet1 in above algo.
    for(int i=1;i<=n;i++){
        if(a[v][i] && !visited[i]){
            q[++r] = i;
        }
    }

    if(f<=r){
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
void main(){
    int v;
    int flag =0;
    printf("\nEnter the number of vertices:\t");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        q[i] = 0;    //This will put the value 0 for all the vertices. Later will be replaced by the vertex only.
        visited[i] = 0;   //This will mark all the nodes as not visited.
    }

    printf("\nEnter the Adjacency matrix:\t");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);  //Here, we are taking the adjacency matrix for the graph
        }
    }

    printf("Enter the starting node:\t");
    scanf("%d",&v);
    bfs(v);

    for(int i=1;i<=n;i++){
        if(visited[i]){
            flag =1;   //Here marking if any one lement is visited.
            break;
        }
    }
    if(flag == 1){
        printf("The nodes which are reachable are:\t");
        for(int i=1;i<=n;i++){
            if(visited[i]){
                printf("%d ",i);  //This will print all the nodes with visited[i] as 1
            }
        }
    }
    else{
        printf("There is no node reachable from the given node!");
    }
}

/*
------------------------O/P 1----------------------------
    Enter the number of vertices:   6

Enter the Adjacency matrix:
0 1 1 0 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 0
0 0 0 1 0 1
0 0 0 0 0 0
Enter the starting node:        5
The nodes which are reachable are:      4 6

------------------------O/P 2----------------------------

Enter the number of vertices:   6

Enter the Adjacency matrix:
0 1 1 0 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 0
0 0 0 1 0 1
0 0 0 0 0 0
Enter the starting node:        3
The nodes which are reachable are:      4 6

------------------------O/P 3----------------------------

Enter the number of vertices:   6

Enter the Adjacency matrix:
0 1 1 0 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 0
0 0 0 1 0 1
0 0 0 0 0 0
Enter the starting node:        1
The nodes which are reachable are:      2 3 4 5 6

Time Complexity: O(V)
Space Complexity: O(V)

*/