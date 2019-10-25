/*DOUBLE LINKED LIST (STORES int)*/

#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* root = NULL;

void append(){

  struct node* temp;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("Please enter int:");
  scanf("%d",&temp->data);
  temp->left = NULL;
  temp->right = NULL;
  if(root==NULL){
    root=temp;    
  } else {
    struct node* p=root;
    while(p->right!=NULL){
      p=p->right;
    }

    temp->left=p;
    p->right=temp;

  }

}

int size(){
  struct node * temp = root;
  if(root==NULL){
    return 0;
  } else {    
    int count = 1;
    while(temp->right!=NULL){
      temp=temp->right;
      count++;
    }
    return count;
    printf("%d",count);
  }
  
}



void prepend(){
  if(size()){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));    
    printf("Enter an integer:\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=root;  
    (temp->right)->left=temp;  
    root=temp;

  } else {
    append();
  }
}


void traverse(){
  if(size()){
    struct node*temp=root;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->right;
    }
  }
}


void deleteLoc(){
  /*dwork*/
  int loc;
  printf("Enter location :");
  scanf("%d",&loc);
  if(loc>size()){
    printf("Invalid\n");
  } else {    
    if(loc==1){      
      struct node* temp_one = root;
      root=temp_one->right;
      root->left=NULL;
      free(temp_one);

    } else {

      struct node *p = root, *q, *r;
      int i=1;
      while(i<loc-1){
        p=p->right;
        i++;
      }
      q=p->right;
      r=p->right->right;

      p->right=q->right;
      r->left=p;
      q->left=NULL;
      q->right=NULL;
      free(q);      
    }
  }
}


void addafter(){
   struct node* temp;
   int loc,len;
   int i=1;
   struct node *p;
   printf("Enter location to add:\n");
   scanf("%d",&loc);
   len=size();
   if(loc<=len){
     temp = (struct node*)malloc(sizeof(struct node));
     printf("Enter in:\n");
     scanf("%d",&temp->data);
     temp->left=NULL;
     temp->right=NULL;
     p=root;
     while(i<loc){
       p=p->right;
       i++;
     }
     temp->left=p;
     temp->right=p->right; 
     p->right->left=temp;
     p->right=temp;

   }
}
/*

void nodeswap(){
  int loc;
  printf("Enter location to swap\n");
  scanf("%d",&loc);
  if(loc>=size()){
    printf("Invalid");
  } else {
    struct node *p=root,*q,*r;
  int i=2;
    while(i<loc){
      p=p->link;
      i++;
    }
    q=p->link;
    r=q->link;

    p->link=q->link;
    q->link=r->link;
    r->link=q;    
  }
}

*/

int main(){

  while(1){
    int ch;
    printf("1. Append, 2. Size, 3. Prepend, 4. Traverse, 5. DeleteLoc, 6. Add after, 7. Node Swap\n\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        append();
        break;
      case 2:
        size();
        break;
      case 3:
        prepend();
        break;
      case 4:
        traverse();
        break;
      case 5:
        deleteLoc();
        break;
      case 6:
        addafter();
        break;
      /*case 7:
        nodeswap();
        break;*/
      
    }
  }
  return 0;
};
