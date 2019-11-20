#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  int isVisited;
};

struct Node *createNode(int data){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->isVisited = 0;
  return newNode;
}

void printlinkedlist(struct Node *head){
  printf("\nLinked List :\n");
  struct Node *temp = head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
};


struct Node * isLoopPresent2(struct Node *head){
  struct Node *temp = head;
  while(temp!=NULL){
    if(temp->isVisited){
        printf("Loop is present!\n\nLoop elements :\n");
        struct Node *startPoint = temp;
        struct Node *movingPoint = temp->next;
        printf("%d ",startPoint->data);
        int lc=1;
        struct Node *lastNodeofLoop = NULL;
        while(movingPoint!=startPoint){
          printf("%d ",movingPoint->data);
          if(movingPoint->next==startPoint){
              lastNodeofLoop = movingPoint;
          }
          movingPoint = movingPoint->next;          
          lc++;
        }        
        //Removed the loop
        lastNodeofLoop->next = NULL;
        return head;
    }
    else {
        temp->isVisited = 1;
        temp = temp->next;
    }
    
  }
  printf("Loop is absent\n");
  return head;
};


int isLoopPresent(struct Node *head){

  //Floyd's Cycle Finding Algo 
  //without using "isVisited"   
  struct Node *slow_p = head;
  struct Node *fast_p = head;
  int start = 1;
  while(fast_p!=NULL){      
      printf("slow_p = %d, fast_p = %d\n", slow_p->data, fast_p->data);
      if(slow_p==fast_p && start!=1) {
        struct Node *temp = slow_p->next;
        int loop_count = 1;
        while(temp!=slow_p){
          printf("%d ", temp->data);
          temp =temp->next;
          loop_count++;
        }
        printf("%d ",temp->data);
        return loop_count;
      }
      slow_p = slow_p->next;
      if(fast_p->next !=NULL) {
        fast_p = fast_p->next->next;
      } else {
        break;
      }

      start = 0;
  }
  return 0;
}





int main(void) {
  struct Node *head = NULL;
  struct Node *node1 = createNode(1);
  struct Node *node2 = createNode(2);
  struct Node *node3 = createNode(3);
  struct Node *node4 = createNode(4);
  struct Node *node5 = createNode(5);
  struct Node *node6 = createNode(6);
  struct Node *node7 = createNode(7);
  struct Node *node8 = createNode(8);
  struct Node *node9 = createNode(9);

  /*
      1-->2-->3-->4-->5-->6-->7-->8-->9                   
      |                               |
      ---------------------------------
  */
  head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;
  node7->next = node8;
  node8->next = node9;
  node9->next = node1;

  printf("Loop = %d", isLoopPresent(head));
  printf("\n\n\n");
  printlinkedlist(isLoopPresent2(head));
  
  //isLoopPresent2
  //printlinkedlist(head);
  
  return 0;
}