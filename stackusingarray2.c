#include <stdio.h>
int size(int *arr, int t){
    printf("Size is %d\n", t+1);
    return t+1;
}
void push(int *arr, int *t, int number){
  if(size(arr,*t)>1000){
    printf("Stack Full\n");
  } else {
    *t+=1;
    arr[*t] = number;
    printf("%d pushed to stack\n", number);
  }
}

int pop(int *arr, int *t){
  int toReturn  = arr[*t];
  *t-=1;
  printf("%d popped from stack\n", toReturn);
  return toReturn;
}

int top(int *arr, int *t){
  printf("%d is top\n", arr[*t]);
  return arr[*t];
}

void print_stack(int *arr, int t){
  printf("\n");
  printf("\n");
  for(int i = 0; i<=t; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("\n");
}
int main(void) {
  int arr[1000];
  int t = -1;
  int al;
  push(arr, &t, 4);
  al = top(arr, &t);
  push(arr, &t, 40);
  push(arr, &t, 425);
  push(arr, &t, 410);
  print_stack(arr ,t);
  al = top(arr, &t);
  push(arr, &t, 44);
  push(arr, &t, 44);
  push(arr, &t, 46);  
  al = top(arr, &t);
  push(arr, &t, 44);
  push(arr, &t, 21);
  print_stack(arr ,t);
  al = top(arr, &t);
  push(arr, &t, 10);
  push(arr, &t, -11);
  int sise;
  sise = size(arr, t);
  int p; 
  p = pop(arr, &t);
  p = pop(arr, &t);
  p = pop(arr, &t);
  p = pop(arr, &t);
  print_stack(arr ,t);
  p = pop(arr, &t);
  p = pop(arr, &t);
  print_stack(arr ,t);
  sise = size(arr, t);

  return 0;
}