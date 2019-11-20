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

struct Node *reverseLinkedList2(struct Node *head, int k,struct Node *tail){
  //printf("Called\n");
  struct Node *curr = head;
  struct Node *prev = NULL;
  struct Node *next = head;
  int count=0;
  int flag = 0;
  while(curr!=NULL && count<k){      
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;    
    count++;                  
  }      


  /*Leave k nodes */
  if(head!=NULL){
    head->next = curr;
  }

  count = 0;
  while(curr!=NULL && count < k-1){
    curr = curr->next;
    count++;
  }
  if(curr!=NULL) curr->next = reverseLinkedList2(curr->next,k,tail);
  /*------------*/


  /*Do not leave k nodes */
  /*if(head!=NULL){
    head->next = reverseLinkedList2(curr->next,k,tail);
  } */  
  /*------------*/
  
  return prev;
}

struct Node* reverseLinkedList(struct Node *head){
  struct Node *curr = head;
  struct Node *prev = NULL;
  struct Node *next = head;
  while(curr!=NULL){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }
  return prev;
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
  head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;
  node7->next = node8;
  node8->next = node9;
  printlinkedlist(head);
  head = reverseLinkedList(head);
  printlinkedlist(head);
  head = reverseLinkedList2(head, 3,NULL);
  printlinkedlist(head);
  return 0;
}