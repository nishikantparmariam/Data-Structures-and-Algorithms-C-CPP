//"ZERO BASED DISTANCE"
//i.e. 
// 1 0
// 1 1
// the answer for distance between (0,0) and (1,1) will be 2

  #include <stdio.h>
  #include <stdlib.h>
  //Queue Utility
  struct Node {
    int x;
    int y;
    struct Node *next;
  };

  int isEmpty(struct Node *head){
    if(head==NULL) return 1;
    else return 0;
  }

  void dequeue(struct Node **head, int *x, int *y){
    struct Node *temp = *head;
    *x = temp->x;
    *y = temp->y;
    *head = temp->next;
    free(temp);
  }

  struct Node *makeNode(int x, int y){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
  }

  void enqueue(struct Node **lastNode, struct Node **head, int x, int y){  
    struct Node *newNode = makeNode(x,y);
    
    if(*head==NULL || *lastNode ==NULL){    
      *head = newNode;
      *lastNode = newNode;
    } else {
      (*lastNode)->next = newNode;
      *lastNode = newNode;
    }
    
  }

  /*void enqueue2(struct Node **head, int x, int y){  
    struct Node *newNode = makeNode(x,y);
    
    if(*head==NULL){
      *head = newNode;
    } else {
      struct Node *temp = *head;
      while(temp->next!=NULL){
          temp = temp->next;
      }
      temp->next = newNode;
    }
  } */

  void traverse(struct Node *head){
    struct Node *temp = head;
    while(temp!=NULL){
      printf("(%d, %d)-->", temp->x, temp->y);
      temp = temp->next;
    }
  }

  //Queue Utility



  void BreadthFirstSearch(int sx, int sy, int dx, int dy, int M, int N,int grid[M][N], int *ans){
      struct Node *head = NULL;
      struct Node *lastNode = NULL;
      //struct Node *lastNode = NULL;
      //enqueue2(&head, sx, sy);
      enqueue(&lastNode,&head, sx,sy);
      grid[sx][sy] = 0;
      int x, y, newLabel;
      
      while(!isEmpty(head)){
          //traverse(head);
          //printf("\n");
          dequeue(&head, &x, &y);
          //traverse(head);
          //printf("\n");
          newLabel = grid[x][y]+1;
          
          if(x-1>=0 && x-1<M){
              if(grid[x-1][y]==-1){
                  grid[x-1][y]=newLabel;
                  //printf(" Added1 = %d %d\n", x-1, y);
                  enqueue(&lastNode,&head, x-1,y);
                  //enqueue2(&head, x-1, y);
              }
          }


          if(x+1>=0 && x+1<M){
              if(grid[x+1][y]==-1){
                  grid[x+1][y]=newLabel;
                  //printf("Added2 = %d %d\n", x+1, y);
                  enqueue(&lastNode,&head, x+1,y);
                  //enqueue2(&head, x+1, y);
              }
          }


          if(y-1>=0 && y-1<N){
              if(grid[x][y-1]==-1){
                  grid[x][y-1]=newLabel;
                  //printf("Added3 = %d %d\n", x, y-1);
                  enqueue(&lastNode,&head, x,y-1);
                  //enqueue2(&head, x, y-1);
              }
          }


          if(y+1>=0 && y+1<N){
              if(grid[x][y+1]==-1){
                  grid[x][y+1]=newLabel;
                  //printf("Added4 = %d %d\n", x, y+1);
                  enqueue(&lastNode,&head, x,y+1);
                  //enqueue2(&head, x, y+1);
              }
          }

          /*traverse(head);
          printf("\n");*/

          //x-1, y
          //x+1, y
          //x, y-1
          //x, y+1        

      }

      *ans = grid[dx][dy];
      /*for(int i = 0; i<M; i++){
      for(int j = 0;j<N; j++){
          printf("%d\t", grid[i][j]);
      }
      printf("\n");
      }*/
    }

  int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    int grid[M][N];
    for(int i = 0; i<M; i++){
      for(int j = 0;j<N; j++){
          int scanned_value;
          scanf("%d", &scanned_value);
          if(scanned_value==1) grid[i][j] = -1;
          else grid[i][j] = 0;
      }
    }
    int source[2];
    int dest[2];
    scanf("%d %d", &source[0], &source[1]);
    scanf("%d %d", &dest[0], &dest[1]);
    int ans;  
    BreadthFirstSearch(source[0], source[1], dest[0], dest[1], M, N, grid, &ans);
    printf("%d", ans);
    return 0;
  }