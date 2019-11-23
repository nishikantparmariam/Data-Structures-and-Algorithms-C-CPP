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

int print_path(int *parent, int j, int a);

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
  
  //from v2 -> v1
  struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
  newNode2->data = v1;
  newNode2->next = G->adjList[v2];
  newNode2->weight = weight;
  G->adjList[v2] = newNode2;   
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

int _min(int a, int b){
  return a>b ? b:a;
}

int give_min_vertex(int *d, int *found_distance_set, int no_of_vertices){
    int min_vertex = 0;
    int min_d = INT_MAX+11;
    for(int i=0; i<no_of_vertices; i++){
        if(found_distance_set[i]==0 && d[i] < min_d){
          min_d = d[i];
          min_vertex = i;
        }
    }

    return min_vertex;
}

void dijktras_algorithm(struct Graph *G, int src, int *parent){
    int d[G->no_of_vertices];
    int found_distance_set[G->no_of_vertices];    
    for(int i = 0; i<G->no_of_vertices; i++){
      d[i] = INT_MAX;
      found_distance_set[i] = 0;
      parent[i] = -1;
    }

    d[src] = 0;


    for(int j = 0; j<G->no_of_vertices-1; j++){
        int min_vertex = give_min_vertex(d, found_distance_set, G->no_of_vertices);        
        found_distance_set[min_vertex] = 1;

        struct Node *temp = G->adjList[min_vertex];
        while(temp!=NULL){
          if(found_distance_set[temp->data]==0){
              if(d[temp->data] > d[min_vertex]+temp->weight){
                  d[temp->data] = d[min_vertex]+temp->weight;
                  parent[temp->data] = min_vertex;
              } 
              //d[temp->data] = _min(d[temp->data], d[min_vertex]+temp->weight);                                          
          }            
          temp = temp->next;          
        }
    }


    for(int i = 0; i<G->no_of_vertices; i++){
      printf("%d, distance from src = %d\n", i, d[i]);
    }
    
}

int main(void) {
  struct Graph *G = createGraph(9);  
  addEdge(G, 0,1,4);  
  addEdge(G, 0,7,8);
  addEdge(G, 7,1,11);
  addEdge(G, 2,1,8);
  addEdge(G, 8,2,2);
  addEdge(G, 3,2,7);
  addEdge(G, 5,2,4);
  addEdge(G, 3,5,14);
  addEdge(G, 3,4,9);
  addEdge(G, 4,5,10);
  addEdge(G, 6,5,2);
  addEdge(G, 6,8,6);
  addEdge(G, 7,6,1);
  addEdge(G, 8,7,7); 
  print_Graph(G); 
  int parent[G->no_of_vertices];
  int src = 0;
  dijktras_algorithm(G, src, parent);      

  printf("\n\n");

  for(int i = 0; i<G->no_of_vertices; i++){
      int j = i;
      printf("From %d to %d\n", src, i);
      print_path(parent, i, 1);      
      printf("\n\n");      
  } 
  return 0;
}

int print_path(int *parent, int j, int a){
    if(j==-1) return 0;
    print_path(parent, parent[j], 0);
    if(a){
        printf("%d", j);    
    } else {
        printf("%d->", j);    
    }
    return 1;
}