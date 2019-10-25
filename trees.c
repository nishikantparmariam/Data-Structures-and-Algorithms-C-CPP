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


struct Root * top(struct Node **first){
    struct Node *temp = *first;
    
    /*struct Root *toReturn = temp->add;
    *first = temp->next;
    free(temp); */
    struct Root *n = NULL;
    if(temp == NULL) return n;
    return temp->add; 
}


int top_v(struct Node **first){
    struct Node *temp = *first;
    
    /*struct Root *toReturn = temp->add;
    *first = temp->next;
    free(temp); */
    struct Root *n = NULL;
    if(temp == NULL) return -1; //Min
    return temp->add->val; 
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

void insertIntoBST(struct Root *p, int key){  
    struct Root *temp = p;
    struct Root *temp_parent = p;
    while(p!=NULL){
        temp_parent = p;
        if(p->val>key){
          p = p->left;

        } else {
          p = p->right;
        }        
    }

    struct Root *newNode = (struct Root *)malloc(sizeof(struct Root));
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> val = key;
    if(temp_parent->val>key){
        temp_parent->left = newNode;
    } else {
      temp_parent->right = newNode;
    }
}


struct Root *RinsertIntoBST(struct Root *p, int key){
  if(p==NULL){
    struct Root *newNode = (struct Root *)malloc(sizeof(struct Root));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = key;
    return newNode;
  } else if(p->val < key){
      p->right = RinsertIntoBST(p->right, key);
  } else {
      p->left = RinsertIntoBST(p->left, key);
  }
  return p;
}



struct Root *successor(struct Root *root){       
  //if right child exists
  struct Root *temp = root->right;
  while(temp->left!=NULL){
    temp = temp->left;
  }
  return temp;        
} 

struct Root *predecessor(struct Root *root){       
  //if left child exists
  struct Root *temp = root->left;
  while(temp->right!=NULL){
    temp = temp->right;
  }
  return temp;        
} 


void deleteFromBST(struct Root *root, int key){
  //search of the key:
  //printf("\ncalled key = %d\n", key);
  struct Root *temp = root;
   struct Root *temp_parent = root;
  //Assuming that key exists
  while(temp->val!=key){
      temp_parent = temp;
      if(temp->val < key){
        temp = temp->right;
      } else {
        temp = temp->left;
      }
  }

  //if leaf
  if(temp->left == NULL && temp->right == NULL){
    if(temp_parent->left == temp){
      temp_parent->left = NULL;
    } else {
      temp_parent->right = NULL;
    }
    free(temp);

  } else if(temp->right!=NULL){
    //if has right subtree
    struct Root *successor1 = successor(temp);    
    int a = successor1->val;
    deleteFromBST(root, a);
    temp->val = a;

  } else {
    struct Root *predecessor1 = predecessor(temp);
    int a = predecessor1->val;   
    deleteFromBST(root, a);
    temp->val = a;
  }
  

  //if has no right subtree
}


void preorder(struct Root *root){

  if(root!=NULL){    
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}


      /*

                  7
              4        8
                5          13
                  6     11
                           12  
     */  


struct Root * RdeleteFromBST(struct Root *root, int key){  
  if(root->val < key){
   
    root->right = RdeleteFromBST(root->right,key);    
  } else if (root->val > key){
    
    root->left = RdeleteFromBST(root->left,key);    
  } else {
    //if leaf 
    if(root->left==NULL && root->right==NULL){      
      free(root);
      return NULL;
    } else if(root->right!=NULL){
      
      struct Root *suc = successor(root);
      root->val = suc->val;
      root->right = RdeleteFromBST(root->right,suc->val);
            
    } else {      
      struct Root *suc = predecessor(root);
      root->val = suc->val;
      root->left = RdeleteFromBST(root->left,suc->val);
    }
  }
  return root;
}

struct Root *create(int key){
  struct Root *root = (struct Root *)malloc(sizeof(struct Root));
  root->left = NULL;
  root->right = NULL;
  root->val = key;
  return root;
}

struct Root* generate(int *preorder, int len){
  struct Node *stack = NULL;
  int i = 0;
  struct Root *root = NULL;
  struct Root *p = NULL;  
  printf("Called\n");
  while(i<len){
      int val = preorder[i];
      if(i==0){
          printf("Made root %d\n", val);
          root = create(val);
          p = root;
          push(&stack, root);
          i++;
      } else {
          int top_ =  top_v(&stack);
         if((top_==-1)||(val < top_)){
              struct Root *temp = create(val);
              p->left = temp;
              p = temp;
              push(&stack, temp);
              printf("Made lc %d\n", val);
              i++;
         } else{
            while(((top_v(&stack))<val) && top_v(&stack)!=-1){
              p = pop(&stack);
              printf("Popped %d\n", p->val);

            }
            //p = pop(&stack);
            struct Root *temp = create(val);
            p->right = temp;
            p = temp;
            push(&stack, temp);
            printf("Made rc %d\n", val);
            i++;
         } 
      }
  }

  return root;
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

    //Insert into BST
    struct Root *rootx = (struct Root *)malloc(sizeof(struct Root));
    rootx->left = NULL;
    rootx->right = NULL;
    rootx->val = 6;    
    insertIntoBST(rootx, 5);
    insertIntoBST(rootx, 4);
    RinsertIntoBST(rootx, 8);
    //insertIntoBST(rootx, 8);
    insertIntoBST(rootx, 7);
    insertIntoBST(rootx, 13);
    insertIntoBST(rootx, 11);
     /*

                  6
              5        8
            4       7    13
                        11  
     */

    preorder(rootx);
    printf("\n\n");
    
    deleteFromBST(rootx, 5);    
    insertIntoBST(rootx, 5);  

    printf("\n\n");    
    deleteFromBST(rootx, 6);    
    insertIntoBST(rootx, 6);
    preorder(rootx);
    printf("\n\n");

    

  RinsertIntoBST(rootx, 12);

      /*

                  7
              4        8
                5          13
                  6     11
                           12  
     */  


  rootx = RdeleteFromBST(rootx, 8);    
  //deleteFromBST(rootx, 8);    
  //
  //insertIntoBST(rootx, 6);

  
      /*

                  7
              4        11
                5          13
                  6     12
                             
     */  


  preorder(rootx);
  rootx = RdeleteFromBST(rootx, 7);

  
      /*

                  11
              4        12
                5          13
                  6     
                             
     */  
  printf("\n\n");
  preorder(rootx);


      /*
      
            10  
        5
           9 
         7
           8
      */ 

    struct Root *rooty = (struct Root *)malloc(sizeof(struct Root));
    rooty->left = NULL;
    rooty->right = NULL;
    rooty->val = 10;        
    RinsertIntoBST(rooty, 5);
    RinsertIntoBST(rooty, 9);
    RinsertIntoBST(rooty, 7);
    RinsertIntoBST(rooty, 8);       
    printf("\n\n");
    preorder(rooty);
    rooty = RdeleteFromBST(rooty, 10);    
    printf("\n\n");

    /*
      
               9  
        5            10
           8                20
         7              12      21  
                           13
      */

    //9      
    preorder(rooty);

    printf("\n\n\n\n\n");
    //generating BST from preorder

    int pre[] = {9, 5, 8, 7, 10, 20, 12, 13, 21};
    struct Root *pr = generate(pre, 9);

    printf("\n\n");
    preorder(pr);
    return 0;
}