#include <stdio.h>
//3 2 1 0
void insertion_sort(int *arr, int len) {
    for(int j = 1; j < len; j++){                
        int i = j-1;
        int temp_index = j;
        while(i>=0){
          if(arr[temp_index]<arr[i]){
              int temp = arr[temp_index];
              arr[temp_index] = arr[i];
              arr[i] = temp;
              temp_index = i;
          } else {
            break;
          }
          i--;
        }
    }
    for(int m = 0; m < len; m++){
        printf("%d\t", arr[m]);
    }
}
int main(void) {
  int arr[] = {3,2,1,0, 12, 100, 78, 45, 5};
  insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
  return 0;
}