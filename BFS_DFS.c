#include <stdio.h>
#include <stdlib.h>

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


void BFS(int n, int Graph[n][n], int start){
  int visited[n];
  int distance[n];
  int parent[n];
  int bfs[n];
  for(int i =0; i<n; i++){
      visited[i] = 0;
      distance[i] = -1;
      parent[i] = -1;
  };
  int count = 0;
  struct Node *head = NULL;
  enqueue(&head, start);
  distance[start] = 0;
  visited[start] = 1;
  bfs[count] = start;
  count++;
  printf("%d ", start);
  while(!isEmpty(&head)){
      int v = dequeue(&head);
      for(int i=0; i<n;i++){
          if(Graph[v][i]==1 && visited[i]==0){
              printf("%d ", i);
              visited[i] = 1;
              parent[i] = v;
              distance[i] = distance[v]+1;
              bfs[count] = i;
              count++;
              enqueue(&head, i);
          }
      }
  }
  

  printf("\n\n");
  for(int i =0; i<n; i++){
    printf("vertex = %d, distance=  %d, parent = %d\n", bfs[i], distance[bfs[i]], parent[bfs[i]]);
  }

}

void DFS(int n, int Graph[n][n], int source, int *visited, int *arrival, int *leaving, int *time, int *dfs, int *count){
    if(visited[source]==0){
      visited[source] = 1;
      arrival[source] = *time;
      (*time) = (*time)+1;
      printf("%d ", source);
      dfs[(*count)] = source;
      (*count)+=1; 
      for(int i = 0; i<n; i++){
          if(Graph[source][i]==1 && visited[i]==0){              
              DFS(n, Graph, i, visited, arrival, leaving, time, dfs, count);
          }
      }
      leaving[source] = *time;
      (*time) = (*time)+1;
    }    
}

int main(void) {  
                    //  0 1 2 3 4 5 6 7 8 9
  int Graph[10][10] = {{0,0,0,0,0,0,0,0,0,0}, //0
                       {0,0,1,0,0,1,0,0,0,0}, //1
                       {0,1,0,1,0,1,1,0,0,0},  //2
                       {0,0,1,0,0,0,1,1,0,0}, //3
                       {0,0,0,0,0,1,0,0,0,0}, //4
                       {0,1,1,0,1,0,0,0,1,1}, //5
                       {0,0,1,1,0,0,0,0,0,0}, //6
                       {0,0,0,1,0,0,0,0,0,0}, //7
                       {0,0,0,0,0,1,0,0,0,0}, //8
                       {0,0,0,0,0,1,0,0,0,0}}; //9

  //BFS
  BFS(10,Graph,5);

  //DFS
  int visited[10];
  int arrival[10];
  int leaving[10];
  int dfs[10];
  for(int i = 0;i<10;i++) {
    visited[i] = 0;
    arrival[i] = -1;
    leaving[i] = -1;    
  }

  int time = 0;
  int count = 1;

  DFS(10, Graph, 5, visited, arrival, leaving, &time, dfs, &count);

  printf("\n\n\n\n");
  for(int i =1; i<10; i++){
    printf("vertex = %d, a =  %d, l = %d\n", dfs[i], arrival[dfs[i]], leaving[dfs[i]]);
  }

  return 0;
}

