#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int isEmpty(struct Node **root){
  if((*root)==NULL){
    return 1;
  } else return 0;  
}

int  pop(struct Node **root, int *size){
  if(!isEmpty(root)){      
      (*size)-=1; 
      int data = (*root)->data;
      struct Node *next = (*root)->next;
      free((*root));
      (*root) = next;
      return data;
  } else return -1;
}

struct Node *top(struct Node **root){
  return (*root);
}

void push(struct Node **root, int data, int *size){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = (*root);
  (*root) = newNode;  
  (*size)+=1;
}

int main(void) {
  int N;
  scanf("%d", &N);
  int preorder[N];
  for(int i = 0; i<N; i++){
    scanf("%d", &preorder[i]);
  }

  struct Node *root = NULL;
  int min_limit = -1;
  int size = 0;
  int ans = 1;
  for(int i = 0; i<N; i++){
      int data = preorder[i];
      if(data>min_limit){
          if(size==0){
              push(&root, data, &size);
          } else {
              if(data<(top(&root)->data)){
                  push(&root, data, &size);
              } else {
                while(size>0 && (top(&root)->data) < data){
                  min_limit = pop(&root, &size);
                }
                push(&root, data, &size);
              }
          }
      } else {
        ans = 0;
        break;
      }
  }

  //40, 30, 35, 80, 100 - YES
  //40, 30, 35, 20, 80, 100 - NO

  if(ans){
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}