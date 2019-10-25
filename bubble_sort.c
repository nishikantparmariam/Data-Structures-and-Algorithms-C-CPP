#include <stdio.h>
//Bubble sort
void bubbleSort(int *arr, int n){
  for(int j = n-1; j > 0; j--){    
    for(int i = 0; i < j; i++){
      //printf("%d", arr[i]);
      if(arr[i]>arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      } 
    }
  }
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
}
int main(void) {
  int n = 9;
  int arr[]= {-44, 44, 0, 1, 5, 4, 47, 45, -99};
  bubbleSort(arr, n);
  return 0;
}