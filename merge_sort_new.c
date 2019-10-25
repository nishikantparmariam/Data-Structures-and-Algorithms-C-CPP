#include <stdio.h>
void print_arr(int *arr, int n){
  for(int i =0; i<n; i++){
    printf("%d ", arr[i]);
  }
}
void merge(int *arr, int start, int middle, int end){

    int n1 = middle-start+1;
    int n2 = end-middle;
    int final_arr[n1+n2];  
    int i = 0;
    int j = 0;
    int k = 0;

    while(i<n1 && j<n2){
      if(arr[start+i]<=arr[middle+1+j]){
        final_arr[k] = arr[start+i];
        i++;
      } else {
        final_arr[k] = arr[middle+1+j];
        j++;
      }
      k++;
    }


    if(i==n1){
      for(int l = j; l < n2; l++){
          final_arr[k] = arr[l+middle+1];
          k++;
      }
    } else if(j==n2) {
      for(int l = i; l < n1; l++){
          final_arr[k] = arr[l+start];
          k++;
      }    
    }

    for(int i = 0; i < n1+n2; i++){
      arr[i+start] = final_arr[i];
    }
}
void mergesort(int *arr, int start, int end){
  if(end!=start){
      int middle = (start + end)/2; 
      //printf("start = %d, middle = %d, end = %d\n\n", start, middle, end);           
      mergesort(arr, start, middle);      
      mergesort(arr, middle+1, end);
      merge(arr, start, middle, end);
  };
};

int main(void) {
  int n = 13;
  int arr[13] = {-59,1 , 5, 111, 22, 9, 80, -12, -5, -4, -44, 0,-3};
  mergesort(arr, 0, n-1);

  print_arr(arr, n);
  return 0;
}