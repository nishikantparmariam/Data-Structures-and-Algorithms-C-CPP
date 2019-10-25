    /*LINKED LIST (STORES int)*/

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
        printf("Please append");
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
      int loc;
      printf("Enter location :");
      scanf("%d",&loc);
      if(loc>size()){
        printf("Invalid\n");
      } else {    
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

    void reverse(){
      if(root!=NULL){
        int i=0;
        int j=size()-1;
        struct node *p = root;
        struct node *q = root;
        while(i<j)
        {
          int k=0;
          
          while(k<j){
            q=q->link;            
            k++;
          } 
          int m=0;
          
          int temp=q->data;
          q->data=p->data;
          p->data=temp;
          i++;j--;
          p=p->link;
          q=root;
        }

      }
    }
    int main(){

      while(1){
        int ch;
        printf("1. Append, 2. Size, 3. Prepend, 4. Traverse, 5. DeleteLoc, 6. Add after, 7. Node Swap, 8. Reverse\n\n");
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
          case 7:
            nodeswap();
            break;
          case 8:
            reverse();
            break;          
        }
      }
      return 0;
    };
