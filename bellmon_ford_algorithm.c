#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 999

struct Graph {
  int no_of_vertices;
  int *visited;
  struct Node **adjList;
};

struct Node {
  int data;
  struct Node *next;
  int weight;
};

int print_path(int *parent, int j, int a, int *d, int original_dest);

struct Graph *createGraph(int no_of_vertices){
  struct Graph* G = (struct Graph *)malloc(sizeof(struct Graph));
  G->no_of_vertices = no_of_vertices;
  G->visited = (int *)malloc(sizeof(int)*(G->no_of_vertices));
  G->adjList = (struct Node **)malloc(sizeof(struct Node *)*(G->no_of_vertices));
    
  for(int i = 0; i<G->no_of_vertices; i++){
    G->visited[i] = 0;
    G->adjList[i] = NULL;
  }
  return G;  
}



void addEdge(struct Graph *G, int v1, int v2, int weight){
  //from v1 -> v2
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = v2;
  newNode->next = G->adjList[v1];
  newNode->weight = weight;
  G->adjList[v1] = newNode;  



  
}

void print_Graph(struct Graph *G){
  for(int i = 0; i<G->no_of_vertices; i++){      
      struct Node *temp = G->adjList[i];
      printf("%d ->", i);
      while(temp!=NULL){
        printf("(%d %d) - ", temp->data, temp->weight);
        temp = temp->next;
      }
      printf("\n");
  }
}


void bellmon_ford_algorithm(struct Graph *G, int src, int *parent, int *d){    
    for(int i = 0; i<G->no_of_vertices; i++){
        d[i] = INT_MAX;
        parent[i] = -1;
    }

    d[src] = 0;
    
    for(int i = 0; i<G->no_of_vertices-1; i++){
        for(int v = 0; v<G->no_of_vertices; v++){
            struct Node *temp = G->adjList[v];
            while(temp!=NULL){
              if(d[temp->data] > d[v] + temp->weight){
                  d[temp->data] = d[v] + temp->weight;
                  parent[temp->data] = v;
              } 
              temp = temp->next;
            }
        }
    }
    
    printf("\n\n");
}

int main(void) {
  struct Graph *G = createGraph(8);  
  //Directed graph
  addEdge(G, 0,1,-1);
  addEdge(G, 0,3,20);
  addEdge(G, 0,7,-3);
  addEdge(G, 7,3,5);
  addEdge(G, 3,4,-2);
  addEdge(G, 4,2,-1);
  addEdge(G, 4,6,18);
  addEdge(G, 4,5,4);
  addEdge(G, 2,5,-2);
  addEdge(G, 5,6,-5);   
  /*struct Graph *G = createGraph(5);

  addEdge(G,0,1,-1);
  addEdge(G,1,4,-1);
  addEdge(G,1,2,-1);
  addEdge(G,2,3,-1);
  addEdge(G,3,0,100);  */

  print_Graph(G); 
  int parent[G->no_of_vertices];
  int src = 0;
  int d[G->no_of_vertices];
  bellmon_ford_algorithm(G, src, parent, d);      

  printf("\n\n");

  for(int i = 0; i<G->no_of_vertices; i++){
      int j = i;
      printf("From %d to %d\n", src, i);
      print_path(parent, i, 1, d, i);      
      printf("\n\n");      
  } 
  return 0;
}

int print_path(int *parent, int j, int a, int *d, int original_dest){  
    if(j==original_dest && a==0){
            printf("Graph has a negetive cycle.");
            exit(0);
    }


    if(j==-1) return 0;
    print_path(parent, parent[j], 0, d, original_dest);
    if(a){
        printf("%d | %d", j, d[j]);    
    } else {        
        printf("%d->", j);    
    }
    return 1;
}