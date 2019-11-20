#include <stdio.h>
#include <stdlib.h>
struct Graph {
  int no_of_vertices;
  int *visited;
  struct Node **adjList;
  int *color;
};

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node **head, int data){
  struct Node *newNode = createNode(data);
  if((*head)==NULL){      
      (*head) = newNode;
  } else {
      struct Node *temp = (*head);
      while(temp->next!=NULL){
        temp = temp->next;
      }
      temp->next = newNode;
  }
}

int dequeue(struct Node **head){
  if((*head)==NULL) return -1;
  struct Node *temp = (*head);
  (*head) = (*head)->next;
  int toReturn = temp->data;
  free(temp);
  return toReturn;
}

int isEmpty(struct Node **head){
  if((*head)==NULL) return 1;
  return 0;
}

struct Graph *createGraph(int no_of_vertices){
  struct Graph* G = (struct Graph *)malloc(sizeof(struct Graph));
  G->no_of_vertices = no_of_vertices;
  G->visited = (int *)malloc(sizeof(int)*(G->no_of_vertices));
  G->adjList = (struct Node **)malloc(sizeof(struct Node *)*(G->no_of_vertices));
  G->color = (int *)malloc(sizeof(int)*(G->no_of_vertices));
    
  for(int i = 0; i<G->no_of_vertices; i++){
    G->visited[i] = 0;
    G->adjList[i] = NULL;
    G->color[i] = -1; //uncolored
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

int BFS(struct Graph *G, int src, int *hasCycle, int *isNotBipartite){
    struct Node *head = NULL;
    printf("%d ",src);
    G->visited[src-1] = 1; 
    G->color[src-1] = 1; //color this
    enqueue(&head, src);   
    while(!isEmpty(&head)){
        int curr = dequeue(&head);
        struct Node *temp = G->adjList[curr-1];
        while(temp!=NULL){


            if((G->color[temp->data-1]==G->color[curr-1]) && (G->visited[temp->data-1]==1)){
                (*isNotBipartite) = 1;
            }



            if(G->visited[temp->data-1]==0){
                printf("%d ", temp->data);
                G->visited[temp->data-1]=1;
                G->color[temp->data-1] = G->color[curr-1] ? 0 : 1;
                enqueue(&head, temp->data);   
            }  else {
                (*hasCycle) = 1;
            }
                        
            temp = temp->next;
        }
    }

    return 1;
} 

int main(void) {
  struct Graph *G = createGraph(8);      
  addEdge(G,7,8);
  addEdge(G,7,2);
  addEdge(G,4,7);
  addEdge(G,1,2);
  addEdge(G,4,1);
  addEdge(G,4,3);
  addEdge(G,6,4);
  addEdge(G,6,5);  

  /* 
      (7,1,3,6) & (8,2,4,5)
  
  */
  //addEdge(G,8,5);  
  print_Graph(G);

  int isNotBipartite = 0;
  int hasCycle = 0;
  printf("\n\n");
  BFS(G, 1, &hasCycle, &isNotBipartite);
  if(hasCycle) printf("\n\nGraph has cycle\n\n");
  if(!isNotBipartite) printf("Graph is bipartite");
  
  return 0;
}