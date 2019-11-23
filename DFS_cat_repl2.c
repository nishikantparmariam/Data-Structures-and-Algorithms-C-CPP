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

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node **head){
  if((*head)==NULL) return 1;
  else return 0;
}

int dequeue(struct Node **head){
  if((*head)==NULL) return -1;
  struct Node *temp = *head;
  int data = temp->data;
  (*head) = temp->next;
  free(temp);
  return data;
}

void enqueue(struct Node **head, int data){
  struct Node *newNode = createNode(data);
  if((*head)==NULL){
      (*head) = newNode;
      return;
  }  
  struct Node *temp = *head;
  while(temp->next !=NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

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

int _min(int a, int b){
  return a>b ? b : a;
}


int DFS(struct Graph *G, int src, int *visited, int maxCats, int catsNow, int *hasCat){    
    if(hasCat[src-1]) {
      catsNow++;
    }
    if(catsNow > maxCats) return 0;
    

    visited[src-1] = 1;

    //if leaf
    struct Node *temp = G->adjList[src-1];
    int no_neighbours = 0;
    int no_visited_neighbours = 0;
    while(temp!=NULL){
        if(visited[temp->data-1]==1) {
          no_visited_neighbours++;
        }
        no_neighbours++;
        temp = temp->next;
    }

    int leaves = 0;
    if(no_visited_neighbours == no_neighbours && no_neighbours == 1) {
        leaves++;
    }
    //if non-leaf
    
    temp = G->adjList[src-1];
    while(temp!=NULL){
      if(visited[temp->data-1]==0){
          if(hasCat[src-1]==0){
            catsNow = 0;
          }
          leaves+=DFS(G, temp->data, visited, maxCats, catsNow,hasCat);
      }
      temp = temp->next;
    }

    return leaves;

}


int main(void) {
  int N, maxCats;
  scanf("%d %d", &N, &maxCats);
  struct Graph *G = createGraph(N);  
  int hasCat[N];
  int visited[N];
  for(int i = 0; i<N; i++){
    scanf("%d ", &hasCat[i]);
    visited[i] = 0;
  }
  int M = N-1;
  int v1, v2;
  while(M--){
    scanf("%d %d", &v1, &v2);
    addEdge(G, v1, v2);
  }

  int ans = DFS(G, 1, visited, maxCats, 0, hasCat);
  printf("%d", ans);
  
  return 0;
}