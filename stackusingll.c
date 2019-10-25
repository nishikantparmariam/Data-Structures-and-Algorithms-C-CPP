/*STACK USING LINKED LIST (STORES int)*/

#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *link;
};

struct node* root = NULL;

void append(){

  struct node* temp;
  temp = (struct node*) malloc(sizeof(struct node));
  printf("Please enter int:");
  scanf("%d",&temp->data);
  temp->link = NULL;
  if(root==NULL){
    root=temp;    
  } else {
    struct node * temp_p;
    temp_p=root;
    while(temp_p->link!=NULL){
      temp_p=temp_p->link;
    }
    temp_p->link=temp;
  }

}

int size(){
  struct node * temp = root;
  if(root==NULL){
    return 0;
  } else {
    /*excluding root node*/
    int count = 1;
    while(temp->link!=NULL){
      temp=temp->link;
      count++;
    }
    return count;
  }
}

void prepend(){
  if(size()){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));    
    printf("Enter an integer:\n");
    scanf("%d",&temp->data);
    temp->link=root;
    root=temp;

  } else {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Please enter int:");
    scanf("%d",&temp->data);
    temp->link = NULL;
    root=temp;
  }
}

void traverse(){
  if(size()){
    struct node*temp=root;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->link;
    }
  }
}

void deleteLoc(){
  int loc = 1;  
    if(loc==1){      
      struct node* temp_one = root;
      root=temp_one->link;
      free(temp_one);
    } else {
      struct node *p = root, *q;
      int i=1;
      while(i<loc-1){
        p=p->link;
        i++;
      }
      q=p->link;
      p->link=q->link;
      q->link=NULL;
      free(q);
    }
  
}

void addafter(){
  if(size()){
    int loc=0;
    int i=1;
    printf("Enter a location where add after\n");
    scanf("%d",&loc);
    struct node * p=root, *q;
    while(i<loc){
      p=p->link;
      i++;
    }
    q=p->link;

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->link=p->link;
    p->link=new;
    printf("Enter int:\n");
    scanf("%d", &new->data);    
  }
}


/*--------------------------STACK FUNCTIONS START-----------------------*/
void push(){
  prepend();
}
void pop(){
  deleteLoc();
} 

void display(){
  traverse();
}
void length(){
  printf("%d",size());
}

int main(){

  while(1){
    int ch;
    printf("1. Push, 2. Pop, 3. Traverse, 4. Length\n\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        length();
        break;
    }
  }
  return 0;
};
