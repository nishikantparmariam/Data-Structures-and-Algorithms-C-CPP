#include <stdio.h>
#include <stdlib.h>

struct Graph_ {
  int V;
  int *visited;
  int **adjList;
}

struct Node {
  int data;
  int next;
}

int DFS(int n, int Graph[n][n], int *visited, int src, int maxCats, int catsNow, int *hasCat){
    if(hasCat[src]) catsNow++;
    if(catsNow>maxCats){
      return 0;
    }
    visited[src] = 1;
    int count = 0;
    int no_vis_neigh = 0;
    int no_neigh = 0;
    int isLeaf = 0;
    for(int v = 0; v<n+1; v++){
        if(Graph[src][v]==1 && visited[v]==1){
            no_vis_neigh++;
        }
        if(Graph[src][v]==1){
            no_neigh++;
        }
    }
    
    if(no_neigh==no_vis_neigh && no_vis_neigh==1){
      isLeaf=1;
    }
    
    
    for(int v = 0; v<n+1; v++){
        if(Graph[src][v]==1 && visited[v]!=1){
            if(!hasCat[src]){
                catsNow = 0;
            }
            count+=DFS(n, Graph, visited, v,maxCats, catsNow, hasCat);
        }
    }
    
    return count+isLeaf;
}

int main(void) {
  int n, maxCats;
  scanf("%d %d", &n, &maxCats);
  int hasCat[n+1];
  hasCat[0] = 0;
  for(int i =1; i<n+1;i++){
    scanf("%d",&hasCat[i]);
  }
  int Graph[n+1][n+1];
  int visited[n+1];
  for(int i =0; i<n+1; i++){
    for(int j =0; j<n+1; j++){
      Graph[i][j] = 0;
    }
    visited[i] = 0;
  }
  
  for(int i = 1; i<n;i++){
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    Graph[v1][v2] = 1;
    Graph[v2][v1] = 1;
  }
  
  
  
  int ans = DFS(n+1, Graph, visited, 1, maxCats, 0, hasCat);
  printf("%d" ,ans);
  return 0;
}