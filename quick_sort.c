#include <stdio.h>
//     45, 45, -45, 10, 5, 545, 
//                          j i
int partition(int arr[], int l, int r){
  int i = l-1;
  int j = r+1;
  int pivot = arr[l];
  while(1){
    do{
      i++;
    }while(arr[i]<pivot);

    do{
      j--;
    }while(arr[j]>pivot);

    if (i<j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    } else {
      return j;
      break;
    }

  }
}
void quick_sort(int arr[], int l, int r){
    if(l<r){
        int p = partition(arr, l, r);
        quick_sort(arr, l, p);
        quick_sort(arr, p+1, r);
    }
}
int main(void) {
  int arr[] = {100,2,3,4,5,6,7,8,9,10,14,15,16,17,18,19,20,21,22};
  int len = sizeof(arr)/sizeof(int);
  quick_sort(arr, 0, len-1);
  for(int mm =0; mm < len; mm++){
    printf("%d\t", arr[mm]);
  }
  return 0;
}