#include <stdio.h>
#include <stdlib.h>
struct Graph {
  int no_of_vertices;
  int *visited;
  struct Node **adjList;
};

struct Node {
  int data;
  struct Node *next;
};

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



void addEdge(struct Graph *G, int v1, int v2){
  //from v1 -> v2
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = v2;
  newNode->next = G->adjList[v1-1];
  G->adjList[v1-1] = newNode;
  
  //from v2 -> v1
  struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
  newNode2->data = v1;
  newNode2->next = G->adjList[v2-1];
  G->adjList[v2-1] = newNode2;   
}

void print_Graph(struct Graph *G){
  for(int i = 0; i<G->no_of_vertices; i++){      
      struct Node *temp = G->adjList[i];
      printf("%d ->", i+1);
      while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
      }
      printf("\n");
  }
}

int main(void) {
  struct Graph *G1 = createGraph(5);
  struct Graph *G2 = createGraph(6);
  addEdge(G1, 1,2);
  addEdge(G1, 1,3);
  addEdge(G1, 1,5);
  addEdge(G1, 2,5);
  addEdge(G2, 5,6);
  print_Graph(G1);
  printf("\n\n");
  print_Graph(G2);
  printf("Hello World\n");
  return 0;
}