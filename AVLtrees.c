#include <stdio.h>
#include <stdlib.h>
//from geeks  for geeks (START)
#define COUNT 10 
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
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
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(struct Node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 

//from geeks  for geeks (END)



int max(int a, int b){
  if(a>b) return a;
  return b;
}

struct Node *createNode(int data){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1;
  newNode->data = data;
  return newNode;
}

int height(struct Node *root){
  if(root==NULL) return 0;
  int lheight = 0;
  int rheight = 0;
  if(root->left!=NULL){
      lheight = root->left->height;
  }
  if(root->right!=NULL){
      rheight = root->right->height;
  }

  return 1+max(lheight, rheight);
}

int balanceFactor(struct Node *root){
  if(root==NULL) return 0;
  return height(root->left)-height(root->right);
}

struct Node *LLRotation(struct Node *root){
  struct Node *a=root;
  struct Node *b = a->left;
  struct Node *c = b->left;
  a->left = b->right;
  b->right = a;
  a->height = height(a);
  c->height = height(c);
  b->height = height(b);
  return b;
}


struct Node *RRRotation(struct Node *root){
  struct Node *a=root;
  struct Node *b = a->right;
  struct Node *c = b->right;
  a->right = b->left;
  b->left = a;
  a->height = height(a);
  c->height = height(c);
  b->height = height(b);
  return b;
}

struct Node *LRRotation(struct Node *root){
  struct Node *a = root;
  struct Node *b = a->left;
  struct Node *c = b->right;
  a->left = c->right;
  b->right = c->left;
  c->left = b;
  c->right = a;
  b->height = height(b);
  a->height = height(a);
  c->height = height(c);
  return c;
}

struct Node *RLRotation(struct Node *root){
  struct Node *a = root;
  struct Node *b = a->right;
  struct Node *c = b->left;
  a->right = c->left;
  b->left = c->right;
  c->right = b;
  c->left = a;
  b->height = height(b);
  a->height = height(a);
  c->height = height(c);
  return c;
}

struct Node *insertIntoAVLtree(struct Node *root, int data){
  if(root==NULL){
      root = createNode(data);
  } else if(root->data > data){
      root->left = insertIntoAVLtree(root->left, data);
  } else {
      root->right = insertIntoAVLtree(root->right, data);
  }

  /*Fixing the AVL property*/
  int bf_root = balanceFactor(root);
  int bf_left = balanceFactor(root->left);
  int bf_right = balanceFactor(root->right);
  if(bf_root==2 && bf_left==1){
      root = LLRotation(root);
      printf("\nLL\n");
  } else if(bf_root==-2 && bf_right==-1){
      root = RRRotation(root);
      printf("\nRR\n");
  } else if(bf_root==2 && bf_left == -1){
      root = LRRotation(root);
      printf("\nLR\n");
  } else if(bf_root==-2 && bf_right==1){
      root = RLRotation(root);
      printf("\nRL\n");
  }
  return root;
}

struct Node *findMin(struct Node *root){
    //if root!=NULL
    struct Node *temp = root;    
    while(temp->left!=NULL){
      temp = temp->left;
    }
    return temp;    
}

struct Node *findMax(struct Node *root){
  //if root!=NULL
    struct Node *temp = root;    
    while(temp->right!=NULL){
      temp = temp->right;
    }
    return temp;    
}

struct Node *deleteFromBST(struct Node *root, int data){
  if(root==NULL){
    printf("Element does not exists\n");
  } else if(root->data > data){
    root->left = deleteFromBST(root->left, data);
  } else if(root->data < data){
    root->right = deleteFromBST(root->right, data);
  } else {
    //delete this node
    if(root->left==NULL && root->right==NULL){
      //leaf 
      free(root);
      root = NULL;
    } else if(root->right!=NULL){
      struct Node *successor = findMin(root->right);
      root->data = successor->data;
      root->right = deleteFromBST(root->right, successor->data);
    } else {
      struct Node *predeccessor = findMax(root->left);
      root->data = predeccessor->data;
      root->left = deleteFromBST(root->left, predeccessor->data);  
    }
  }

  /*Fixing the AVL property*/
  if(root!=NULL){
    int bf_root = balanceFactor(root);
    int bf_left = balanceFactor(root->left);
    int bf_right = balanceFactor(root->right);
    if(bf_root==2 && bf_left==1){
        root = LLRotation(root);
        printf("\nLL\n");
    } else if(bf_root==-2 && bf_right==-1){
        root = RRRotation(root);
        printf("\nRR\n");
    } else if(bf_root==2 && bf_left == -1){
        root = LRRotation(root);
        printf("\nLR\n");
    } else if(bf_root==-2 && bf_right==1){
        root = RLRotation(root);
        printf("\nRL\n");
    }
  }
  return root;
}

void inorder(struct Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main(void) {
  struct Node *root = NULL;
  root = insertIntoAVLtree(root, 18);
  root = insertIntoAVLtree(root, 17);
  root = insertIntoAVLtree(root, 16);
  root = insertIntoAVLtree(root, 15);
  root = insertIntoAVLtree(root, 14);
  root = insertIntoAVLtree(root, 13);
  root = insertIntoAVLtree(root, 12);
  root = insertIntoAVLtree(root, 11);  
  root = insertIntoAVLtree(root, 10);
  root = insertIntoAVLtree(root, 9);
  root = insertIntoAVLtree(root, 8);
  root = insertIntoAVLtree(root, 7);
  root = insertIntoAVLtree(root, 6);
  root = insertIntoAVLtree(root, 5);
  root = insertIntoAVLtree(root, 4);
  root = insertIntoAVLtree(root, 3);
  root = insertIntoAVLtree(root, 2);
  root = insertIntoAVLtree(root, 1);  
  
  
  inorder(root);
  printf("\n\n");
  print2D(root);
  root = deleteFromBST(root, 8);
  //root = deleteFromBST(root, 9);
  inorder(root);
  printf("\n\n");
  printf("\n\n");
  printf("\n\n");
  printf("\n\n");
  print2D(root);
  return 0;
}