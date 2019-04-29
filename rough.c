#include<stdio.h>

void dijkstra(int source,int cost[20][20],int visited[20],int d[20],int n)
  { 
    int i,j,min,u,w;
    for(i=1;i<=n;i++)
     {
	 	visited[i]=0;//visited[] is empty 
        d[i]=cost[source][i];//d[] stores the source row of the matrix
     } 
    visited[source]=1;//the source is now visited
    d[source]=0;//it takes nothing (no traversing) to reach the source
    
    for(j=2;j<=n;j++)
    {
     min=111;
     for(i=1;i<=n;i++)
      {
       if(!visited[i])//if the vertex is not visited
	     {
	       if(d[i]<min)//even if there's one distance lesser than 111, find the minimum weight to an unvisited node
	       {
	         min=d[i];
	         u=i;
	        }
	      }
      }
     visited[u]=1;//mark the minimum node visited
     for(w=1;w<=n;w++)
     	if(cost[u][w]!=111&&visited[w]==0)//Now continue from the row of the minimum node, and update the distance matrix
       		if(d[w]>cost[u][w]+d[u])
        		 d[w]=cost[u][w]+d[u];
	}
}
  
int main()
{ 
  int n,i,j,visited[20],source,cost[20][20],d[20];
  printf("Enter the number of vertices:\n");
  scanf("%d",&n);
  printf("Enter the cost matrix:\n");
  for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
   			scanf("%d",&cost[i][j]);
  printf("Enter the source node\n");
  scanf("%d",&source);
  
  dijkstra(source,cost,visited,d,n);
  
  for(i=1;i<=n;i++)
  	if(i!=source)
  		printf("\nShortest path from %d to %d is %d ",source,i,d[i]);
  return 0;	
}
