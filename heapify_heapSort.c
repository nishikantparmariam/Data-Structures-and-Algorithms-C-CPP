#include <stdio.h>
#include <math.h>
void print_array(int *arr, int N){
  printf("\n");
  for(int i = 0; i<N; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int give_index(int i){
  return i-1;
}
void heapify(int *arr, int i, int N){
  //max heap formation
  int left_index = 2*i;
  int right_index = 2*i+1;

  
  if(left_index > N){
    //Both child do not exists    
  } else if(right_index>N && left_index<=N){
    //Only left child exists 
    if(arr[give_index(i)]<arr[give_index(left_index)]){
        int temp = arr[give_index(left_index)];
        arr[give_index(left_index)] = arr[give_index(i)];
        arr[give_index(i)] = temp;
        heapify(arr, left_index, N);
    }
  } else {
    //Both child exits
    if(arr[give_index(i)]>arr[give_index(left_index)] && arr[give_index(i)]>arr[give_index(right_index)]){

    } else {
      if(arr[give_index(left_index)]>arr[give_index(right_index)]){
        int temp = arr[give_index(left_index)];
        arr[give_index(left_index)] = arr[give_index(i)];
        arr[give_index(i)] = temp;
        heapify(arr, left_index, N);        
      } else {
        int temp = arr[give_index(right_index)];
        arr[give_index(right_index)] = arr[give_index(i)];
        arr[give_index(i)] = temp;
        heapify(arr, right_index, N); 
      }
    }
  }
  

}
int main(void) {
  int N = 15;
  int arr[] = {5,11,-4,45,10,3,0,100, 1010, 200, 15, -150, 23, 17, 10};
  printf("\nGiven array is :\n");
  print_array(arr,N);
  //N/2 + 1 to N are leaves which are already heap;
  for(int i = floor(N/2); i>0; i--){
    heapify(arr,i, N);
  }  
  printf("\nMax heap is :\n");
  print_array(arr,N);
  printf("\nSorted array is :\n");
  for(int i = N; i>0; i--){    
    int temp = arr[give_index(i)];
    arr[give_index(i)] = arr[give_index(1)];
    arr[give_index(1)] = temp;
    heapify(arr, 1, i-1);
  }
  print_array(arr,N);
  return 0;
}