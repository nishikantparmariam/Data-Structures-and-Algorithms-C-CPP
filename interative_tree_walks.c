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

void preorder(struct Root *root){

  if(root!=NULL){    
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}

int main(void) {
  struct Root *root1 = (struct Root *)malloc(sizeof(struct Root));
  root1->left = NULL;
  root1->right = NULL;
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
    
    */


    struct Node *stk = NULL;
    struct Root *t = root6;
    printf("\n\n");
    //Pre-order Iterative
    while(t!=NULL || !isEmpty(&stk)){    
        if(t!=NULL){
            printf("%d ",t->val);            
            push(&stk, t);
            t = t->left;
        } else {
          t = pop(&stk);
          t = t->right;          
        }
    }


    printf("\n\n");
    //In-order Iterative
    stk = NULL;
    t = root6;
    while(t!=NULL || !isEmpty(&stk)){    
        if(t!=NULL){                       
            push(&stk, t);
            t = t->left;
        } else {
          t = pop(&stk);
          printf("%d ",t->val); 
          t = t->right;          
        }
    }


    //Post-order Iterative
    stk = NULL;
    t = root6;
    while(t!=NULL || !isEmpty(&stk)){    
        if(t!=NULL){                       
            push(&stk, t);
            t = t->left;
        } else {
          t = pop(&stk);          
          t = t->right;          
        }
    }



    return 0;
}