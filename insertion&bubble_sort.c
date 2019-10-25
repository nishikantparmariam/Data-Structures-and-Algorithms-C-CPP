#include <stdio.h>
void bubbleSort(int *arr, int n){
  for(int i = n-1; i>0; i--){
    for(int j = 0; j<i; j++){
      if(arr[j]>arr[j+1]){
        //swap
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n\n");
}

void insertionSort(int *arr, int n){
    for(int i = 1; i < n; i++){
      int key = arr[i];
      for(int j = i-1; j >= -1; j--){
          if(j==-1){
            arr[j+1] = key;
          } else if (arr[j]>key){
              arr[j+1] = arr[j];
          } else {
            arr[j+1] = key;
            break;
          }
      }
    }
    for(int i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
}
int main(void) {
  //int n = 10;
  int arr[8] = {-1, -2, -3, -4, 0, 99, 45, 12};
  int arr2[8] = {-1, -2, -3, -4, 0, 99, 45, 12};
  bubbleSort(arr, 8);
  insertionSort(arr2, 8);
  return 0;
}