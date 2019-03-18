#include<stdio.h>


int n,a[20][20],q[20],visited[20],f=0,r=-1;

void bfs(int v){

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
    int v,flag=0;
    printf("\nEnter the number of vertices:\t");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        q[i] =0;
        visited[i] = 0;
    }

    printf("\nEnter the adjacency matrix:\t");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter the starting node:\t");
    scanf("%d",&v);

    bfs(v);

    for(int i=1;i<=n;i++){
        if(visited[i]){
            flag =1;
            break;
        }
    }

    if(flag == 1){
        printf("The nodes reachable from the source node are:\t");
        for(int i=1;i<=n;i++){
            if(visited[i]){
                printf("%d ",i);
            }
        }
    }
    else{
        printf("There is no node reachable from the source node");
    }
}
//Time complexity: O(E+V)
//Space Complexity: O(V) //Not sure!!