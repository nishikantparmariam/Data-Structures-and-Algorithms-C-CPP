#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Root *add;
  struct Node *next;
};

struct Root {
  int val;
  struct Root *left;
  struct Root *right;
};

void enqueue(struct Node **root, struct Root *toInsert){
    struct Node *newNode  = (struct Node *) malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->add = toInsert;
    struct Node *temp = *root;
    if(*root == NULL){
      *root = newNode;
    } else {
      while(temp->next!=NULL){
        temp = temp->next;      
      } 
      temp->next = newNode;
    }        
}


struct Root * dequeue(struct Node **first){
    struct Node *temp = *first;
    struct Root *toReturn = temp->add;
    *first = temp->next;
    free(temp);
    return toReturn; 
}


void push(struct Node **first, struct Root *root){
  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
  temp->add = root;
  temp->next = *first;
  *first = temp;
}

int isEmpty(struct Node **first){
  if(*first==NULL){
    return 1;
  } else return 0;
}

struct Root * pop(struct Node **first){
    struct Node *temp = *first;
    struct Root *toReturn = temp->add;
    *first = temp->next;
    free(temp);
    return toReturn; 
}

int countNumberofNodes(struct Root *p){
  if(p!=NULL){
    int x = countNumberofNodes(p->left);
    int y = countNumberofNodes(p->right);
    return x+y+1;
  } else {
    return 0;
  }
}

int max(int x, int y){
  if(x>y) return x;
  return y;
}

int height(struct Root *p){
  if(p!=NULL){
    return 1+max(height(p->left),height(p->right));
  } else {
    return 0;
  }
}

int numberofleaves(struct Root *p){
  if(p==NULL){
    return 0;
  } else if(p->left==NULL && p->right == NULL){
    return 1;
  } else {
    return numberofleaves(p->left)+numberofleaves(p->right);
  }
}

void preorder(struct Root *root){

  if(root!=NULL){    
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}

int main(void) {

  struct Root *root0 = (struct Root *)malloc(sizeof(struct Root));
  root0->left = NULL;
  root0->right = NULL;
  root0->val = 0;


  struct Root *root1 = (struct Root *)malloc(sizeof(struct Root));
  root1->left = NULL;
  root1->right = root0;
  root1->val = 1;

  struct Root *root2 = (struct Root *)malloc(sizeof(struct Root));
  root2->left = NULL;
  root2->right = NULL;
  root2->val = 2;

  struct Root *root3 = (struct Root *)malloc(sizeof(struct Root));
  root3->left = NULL;
  root3->right = NULL;
  root3->val = 3;

  struct Root *root4 = (struct Root *)malloc(sizeof(struct Root));
  root4->left = NULL;
  root4->right = root1;
  root4->val = 4;

  struct Root *root5 = (struct Root *)malloc(sizeof(struct Root));
  root5->left = root3;
  root5->right = root2;
  root5->val = 5;

  struct Root *root6 = (struct Root *)malloc(sizeof(struct Root));
  root6->left = root5;
  root6->right = root4;
  root6->val = 6;

  //printf("%d %d %d %d %d %d\n", root6->val, root5->val,root4->val,root3->val,root2->val,root1->val);
  preorder(root6);

    /*
    
            6
       5         4 
    3    2         1 
                      0
    
    */

    printf("\n\n");
    struct Node *root = NULL;
    enqueue(&root, root6);    
    while(!isEmpty(&root)){
      struct Root *p =  dequeue(&root); 
      printf("%d ", p->val);
      if(p->left!=NULL){
          enqueue(&root, p->left);    
      }
      if(p->right!=NULL){
          enqueue(&root, p->right);    
      }
    }

    printf("\n\n");
    printf("No. of Nodes = %d\n", countNumberofNodes(root6));
    printf("Height of tree = %d\n", height(root6));
    printf("No. of leaves of tree = %d\n", numberofleaves(root6));
    return 0;
}