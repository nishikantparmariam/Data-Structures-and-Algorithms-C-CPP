#include <stdio.h>
void print_arr(int *arr, int n){
  for(int i =0; i<n; i++){
    printf("%d ", arr[i]);
  }
}
void selection_sort(int *arr, int n){
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
        if(arr[j]<arr[i]){
          int temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
        }
    }
  }
}
int main(void) {
  int n = 12;
  int arr[12] = {7, -3, -2, -1, 6, 5, 4, 3, 2, 1, 8, 9};
  selection_sort(arr, n);
  print_arr(arr, n);
  return 0;
}