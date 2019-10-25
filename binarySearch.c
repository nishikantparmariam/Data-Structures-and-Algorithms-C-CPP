#include <stdio.h>
int binarySearch(int key, int arr[], int low, int high){
  if(low>high){
      return -1;
  } else {
    int mid = (low+high)/2;
    if(key==arr[mid]){
      return mid;
    } else if(key<arr[mid]){
      return binarySearch(key, arr, low, mid-1);
    } else {
      return binarySearch(key, arr, mid+1, high);
    }
  }
};
int main(void) {
  int arr[] = {1,2,3,55,89,99, 101};
  printf("%d", binarySearch(101, arr, 0, sizeof(arr)/sizeof(int)-1));
  return 0;
}