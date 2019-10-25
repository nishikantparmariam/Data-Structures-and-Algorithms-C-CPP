#include <stdio.h>
//3 2 1 0
void selection_sort(int *arr, int len) {
    for(int j = 0; j< len; j++){
        int min_index = j;
        for(int i = j; i<len; i++){
            if(arr[min_index]>arr[i]){
                min_index = i;
            }
        }
        //insert
        int temp = arr[j];
        arr[j] = arr[min_index];        
        arr[min_index] = temp;
    }
    for(int m = 0; m < len; m++){
        printf("%d\t", arr[m]);
    }
}
int main(void) {
  int arr[] = {111111,3,2,1,0, 12, 100, 78, 45, 5};
  selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
  return 0;
}