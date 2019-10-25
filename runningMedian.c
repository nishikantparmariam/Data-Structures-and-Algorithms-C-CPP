#include <stdio.h>
#include <math.h>
int give_index(int i){
  return i-1;
}
void maxHeapify(int *arr, int i, int N){
  int left_child = 2*i;
  int right_child = 2*i+1;
  if(right_child<=N){
      if(arr[give_index(i)]>=arr[give_index(left_child)] && arr[give_index(i)]>=arr[give_index(right_child)]){
        
      } else {
        if(arr[give_index(left_child)]>arr[give_index(right_child)]){
          int temp = arr[give_index(left_child)];
          arr[give_index(left_child)] = arr[give_index(i)];
          arr[give_index(i)] = temp;
          maxHeapify(arr, left_child, N);
        } else {
          int temp = arr[give_index(right_child)];
          arr[give_index(right_child)] = arr[give_index(i)];
          arr[give_index(i)] = temp;
          maxHeapify(arr, right_child, N);
        }
      }
  } else if(left_child<=N){
    if(arr[give_index(i)]>=arr[give_index(left_child)]){
      
    } else {
      int temp = arr[give_index(left_child)];
      arr[give_index(left_child)] = arr[give_index(i)];
      arr[give_index(i)] = temp;
      maxHeapify(arr, left_child, N);
    }
  }
}
int deleteMax(int *arr,int N){
  int toReturn=arr[0];
  arr[give_index(1)]=arr[give_index(N)];
  maxHeapify(arr,1,N-1);
  return toReturn;
}
void minHeapify(int *arr, int i, int N){
  int left_child = 2*i;
  int right_child = 2*i+1;
  if(right_child<=N){
      if(arr[give_index(i)]<=arr[give_index(left_child)] && arr[give_index(i)]<=arr[give_index(right_child)]){
        
      } else {
        if(arr[give_index(left_child)]<arr[give_index(right_child)]){
          int temp = arr[give_index(left_child)];
          arr[give_index(left_child)] = arr[give_index(i)];
          arr[give_index(i)] = temp;
          minHeapify(arr, left_child, N);
        } else {
          int temp = arr[give_index(right_child)];
          arr[give_index(right_child)] = arr[give_index(i)];
          arr[give_index(i)] = temp;
          minHeapify(arr, right_child, N);
        }
      }
  } else if(left_child<=N){
    if(arr[give_index(i)]<=arr[give_index(left_child)]){
      
    } else {
      int temp = arr[give_index(left_child)];
      arr[give_index(left_child)] = arr[give_index(i)];
      arr[give_index(i)] = temp;
      minHeapify(arr, left_child, N);
    }
  }
}
int deleteMin(int *arr,int N){
  int toReturn=arr[0];
  arr[give_index(1)]=arr[give_index(N)];
  minHeapify(arr,1,N-1);
  return toReturn;
}


void bottomUpMaxHeap(int *arr,int i){
    if(i!=1){
      int parent_index = floor(i/2);
      if(arr[give_index(parent_index)]<arr[give_index(i)]){
        int temp = arr[give_index(parent_index)]; 
        arr[give_index(parent_index)] = arr[give_index(i)];
        arr[give_index(i)] = temp;
        bottomUpMaxHeap(arr, parent_index);
      }  
    }
}
void insertMax(int *arr, int N, int number){
  arr[give_index(N+1)] = number;
  bottomUpMaxHeap(arr,N+1);
}





void bottomUpMinHeap(int *arr,int i){
    if(i!=1){
      int parent_index = floor(i/2);
      if(arr[give_index(parent_index)]>arr[give_index(i)]){
        int temp = arr[give_index(parent_index)]; 
        arr[give_index(parent_index)] = arr[give_index(i)];
        arr[give_index(i)] = temp;
        bottomUpMaxHeap(arr, parent_index);
      }  
    }
}
void insertMin(int *arr, int N, int number){
  arr[give_index(N+1)] = number;
  bottomUpMinHeap(arr,N+1);
}

void print_array(int *arr, int N){
  for(int i = 0; i<N; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int N;
  scanf("%d", &N);
  int LeftMaxHeap[N];
  int N1=0;
  int N2=0;
  int RightMinHeap[N];
  float median_now;
  for(int i=0; i<N; i++){
    int number;
    scanf("%d", &number);
    printf("No. is = %d\n", number);
    if(i==0){
      median_now = number;
    }
    
    if(N1==N2){
      
      
      printf("N1=N2\n");
      if(number<=median_now){
        insertMax(LeftMaxHeap, N1++, number);
        median_now = (float) LeftMaxHeap[0];
      } else {
        insertMin(RightMinHeap, N2++, number);
        median_now = (float) RightMinHeap[0];
      }
      
      
      
    } else if(N1>N2) {
      
      printf("N1>N2\n");
      if(number<=median_now){
        insertMax(LeftMaxHeap, N1++, number);
        int deleted = deleteMax(LeftMaxHeap, N1--);
        insertMin(RightMinHeap, N2++, deleted);
        
      } else {
        insertMin(RightMinHeap, N2++, number);
      }
      
      median_now = (float) (RightMinHeap[0]+LeftMaxHeap[0])/2;
      
    } else {
      
      printf("N1<N2\n");
      if(number<=median_now){
        insertMax(LeftMaxHeap, N1++, number);
        
      } else {
        
        insertMin(RightMinHeap, N2++, number);
        int deleted = deleteMin(RightMinHeap, N2--);
        insertMax(LeftMaxHeap, N1++, deleted);
        
      }
      
      median_now = (float) (RightMinHeap[0]+LeftMaxHeap[0])/2;
      
    }
    
    printf("Left Heap : ");
    print_array(LeftMaxHeap, N1);
    printf("Right Heap : ");
    print_array(RightMinHeap, N2);
    printf("%0.1f\n", median_now);
  }
  return 0;
}
