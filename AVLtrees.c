#include <stdio.h>
#include <stdlib.h>
#define COUNT 10 

struct Node {
  int data;
  struct Node* lchild;
  struct Node* rchild;
  int height;
};

void print2DUtil(struct Node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->rchild, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->lchild, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(struct Node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b){
  return a>b ? a:b;
}

int heightOfNode(struct Node *root){  
  int heightL = 0;
  int heightR = 0;
  if(root==NULL){
    return 0;
  }
  if(root->lchild !=NULL){
      heightL = root->lchild->height;
  }
  if(root->rchild !=NULL){
      heightR = root->rchild->height;
  }
      
  return max(heightL, heightR)+1;
}

struct Node *LLrotation(struct Node *a){
    
    struct Node *b = a->lchild;
    struct Node *c = b->lchild;    
    a->lchild = b->rchild;
    b->rchild = a;    
    a->height = heightOfNode(a);
    c->height = heightOfNode(c);
    b->height = heightOfNode(b);
    return b;
}

struct Node *RRrotation(struct Node *a){
    struct Node *b = a->rchild;
    struct Node *c = b->rchild;
    a->rchild = b->lchild;
    b->lchild = a;    
    a->height = heightOfNode(a);
    c->height = heightOfNode(c);
    b->height = heightOfNode(b);
    return b;
}

struct Node *LRrotation(struct Node *a){
  struct Node *b = a->lchild;
  struct Node *c = b->rchild;
  b->rchild = c->lchild;
  a->lchild = c->rchild;
  c->lchild = b;
  c->rchild = a;  
  a->height = heightOfNode(a);
  b->height = heightOfNode(b);
  c->height = heightOfNode(c);
  return c;
}

struct Node *RLrotation(struct Node *a){
  struct Node *b = a->rchild;
  struct Node *c = b->lchild;
  b->lchild = c->rchild;
  a->rchild = c->lchild;
  c->lchild = a;
  c->rchild = b;
  a->height = heightOfNode(a);
  b->height = heightOfNode(b);
  c->height = heightOfNode(c);
  return c;
}


int balanceFactor(struct Node *root){
  if(root == NULL) return 0;
  return heightOfNode(root->lchild) - heightOfNode(root->rchild);
}

struct Node* insertIntoBST(struct Node *root, int data){  
    if(root==NULL){
        return createNode(data);
    } else if(root->data < data){
        root->rchild = insertIntoBST(root->rchild, data);
    } else {
        root->lchild = insertIntoBST(root->lchild, data);
    }  
      
    int bf_root = balanceFactor(root);        
    int bf_lchild = balanceFactor(root->lchild);    
    int bf_rchild = balanceFactor(root->rchild);    
    root->height = heightOfNode(root);    
    if(bf_root==2 && bf_lchild==1){  
          printf("LL - rotation on %d", data);        
          return LLrotation(root);          
    } else if(bf_root==-2 && bf_rchild==-1){
          return RRrotation(root);
    } else if(bf_root==2 && bf_lchild==-1){
          return LRrotation(root);
    } else if(bf_root==-2 && bf_rchild==1){
          return RLrotation(root);
    }        
    return root;
}

void inorder(struct Node *root){
  if(root == NULL) return;
  inorder(root->lchild);
  printf("data = %d, height = %d\n", root->data, root->height);
  inorder(root->rchild);
}

int main(void) {
  struct Node *root = insertIntoBST(NULL, 13);  
  root = insertIntoBST(root, 12);
  print2D(root);
  printf("\n\n\n\n\n");
  root = insertIntoBST(root, 11);  
  root = insertIntoBST(root, 10);
  print2D(root);
  printf("\n\n\n\n\n");
  root = insertIntoBST(root, 9);
  print2D(root);
  printf("\n\n\n\n\n");
  root = insertIntoBST(root, 8);
  print2D(root);
  printf("\n\n\n\n\n");
  root = insertIntoBST(root, 7);
  print2D(root);
  printf("\n\n\n\n\n");
  root = insertIntoBST(root, 6);    
  print2D(root);
  printf("\n\n\n\n\n");
  print2D(root);
  return 0;
}