#include <stdio.h>
int partition(int *arr, int start, int end){
  int pivot = arr[start];  
  int i = start;
  int j = end;
  while(1){
    while(arr[i]<=pivot){
      i++;
    }
    while(arr[j]>pivot){
      j--;
    }
    if(i<j){
      int temp  =arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    } else {
      int temp  = arr[start];
      arr[start] = arr[j];
      arr[j] = temp;
      break;
    }    
  }
  return j;
}
void print_array(int *arr, int start, int end){
  for(int i = start; i<=end; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int select(int *arr, int k, int start, int end){    
  if(k > end-start+1){
    return -1;
  } else if(start==end){
    return arr[start];
  } else {    
    int p = partition(arr, start, end);    
    int length_of_left = p-start;
    if(length_of_left == k-1){
      return arr[p];
    } else if(length_of_left>=k) {
      return select(arr, k, start, p-1);
    } else {
      return select(arr, k-length_of_left-1, p+1, end);
    }
  }
}
int main(void) {
  for(int i = 1; i<=19; i++){
      int arr[] = {199,32,150,160,56,150,19,8,140,26,15,31,21,130,25,2,5,120,200};
      int k = i;
      printf("%d\n", select(arr, k, 0, 18));
  }
  return 0;
}