#include <stdio.h>
int size(int *arr, int t){    
    return t+1;
}
void push(int *arr, int *t, int number){
  if(size(arr,*t)>1000){    
  } else {
    *t+=1;
    arr[*t] = number;    
  }
}

int pop(int *arr, int *t){
  int toReturn  = arr[*t];
  *t-=1;  
  return toReturn;
}

int top(int *arr, int *t){  
  return arr[*t];
}

void print_stack(int *arr, int t){  
  for(int i = 0; i<=t; i++){
    printf("%d ", arr[i]);
  }  
}
int main(void) {  
    int prices = {70, 40, 50,60,30,80,50,60,20,10,40};
    int lenStocks = sizeof(prices)/sizeof(int);
    int hi_stack[N];
    hi_stack[0] = 0;
    int t = 0;
    int span[N];
    span[0] = 1;
    for(int i = 1; i<lenStocks; i++){
        while(prices[i]>=prices[top(hi_stack, &t)] && t+1>0){
            int deleted = pop(hi_stack, &t);
        }
        span[i] = i-top(hi_stack, &t);
        push(hi_stack, &t, i);
    }
    print_array(span, lenStocks);
    return 0;
}