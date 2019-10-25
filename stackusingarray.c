/*STACK IMPLEMENTATION (using array) (STORES int)*/

#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 5

int stack[CAPACITY];
int top = -1; 

int isFull(){
  if(top==CAPACITY-1){
    return 1;
  }else{
    return 0;
  }
}

void push(int element){
  if(!isFull()){

    top++;
    stack[top]=element;    

  } else {    
  }
}

int isEmpty(){
  if(top==-1){
    return 1;
  } else {
    return 0;
  }
}

int pop(){
  
  if(!isEmpty()){

    int temp = stack[top];
    stack[top]=0;
    top--;
    return temp;    

  } else {    
    return 0;
  }
}

int peak(){
  if(!isEmpty()){
    return stack[top];
  } else {
    return 0;
  }
}

void traverse(){
  if(!isEmpty()){
    for(int i=0;i<=top; i++){
      printf("%d\t",stack[i]);
    }
  }
}

int main(){
    
  return 0;
}
