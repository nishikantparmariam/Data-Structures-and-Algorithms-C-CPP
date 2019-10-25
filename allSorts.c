#include <stdio.h>
#include <stdlib.h>
void print_array(int *arr, int n){
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
};

void selectionSort(int *arr, int n){
  for(int j = 0; j<n-1; j++){    
    for(int i = j+1; i<n; i++){
      if(arr[i]<arr[j]){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }    
  }
}

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
}

void insertionSort(int *arr, int n){
  for(int j = 1; j<n; j++){
    int toInsert = arr[j];
    for(int i = j-1; i>=-1; i--){
      if(arr[i]>toInsert && i!=-1){          
          arr[i+1] = arr[i];          
      } else {
          arr[i+1] = toInsert;
          break;
      }
    }    
  }  
}
void merge(int *arr, int start, int middle, int end){
    int i = 0;
    int j = 0;
    int k = 0;
    int n = middle-start+1;
    int m = end-middle;    
    int merged_array[n+m];

    while(i<n && j < m){
      if(arr[start+i]<arr[middle+1+j]){
          merged_array[k] = arr[start+i];
          i++;
      } else {
          merged_array[k] = arr[middle+j+1];
          j++;
      }
      k++;
    }

    if(i==n){
      for(int l = j; l < m; l++){
        merged_array[k] = arr[middle+l+1];
        k++;        
      }
    } else if(j==m){
      for(int l = i; l < n; l++){
        merged_array[k] = arr[start+l];
        k++;        
      }
    }

    for(int i = 0; i < n+m; i++){
      arr[start+i] = merged_array[i];
    }
}

void mergeSort(int *arr, int start, int end){
  if(start<end){
    int middle = (start+end)/2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);
    merge(arr, start, middle, end);
  }
}

int quickSortInplacePartition(int *arr, int start, int end){
  int rand_index = (start+end)/2;    //Can be any index between start and end (Inclusive)
  int pivot_element = arr[rand_index]; 
  int i = start;
  int j = end;
  while(1){    
    while(arr[i]<pivot_element){
      i++;
    }    
    while(arr[j]>pivot_element){
      j--;
    };
    if(i<j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;  
    }  else {
      return j;
    }
  }  
}

int quickSortNotInplacePartition(int *arr, int start, int end){
  int pivot_element = arr[start];
  int lc = 0;
  int mc = 0;
  int rc = 0;
  for(int i = 0; i<end-start+1; i++){
    if(arr[start+i]<pivot_element){
      lc++;
    } else if(arr[start+i]==pivot_element){
      mc++;
    } else {
      rc++;
    }
  }

  int final_array[lc+mc+rc];
  int l, m, r;
  l=0; m=0; r=0;
  for(int i = 0; i<end-start+1; i++){
    if(arr[start+i]<pivot_element){
        final_array[l] = arr[start+i];
        l++;
    } else if(arr[start+i]==pivot_element){
        final_array[lc+m] = arr[start+i];
        m++;
    } else {
        final_array[r+lc+mc] = arr[start+i];
        r++;
    }
  }

  for(int i = 0; i<end-start+1; i++){
    arr[start+i] = final_array[i];
  }
  return lc+start;
}

void quickSort(int *arr, int start, int end){
  if(start<end){
    int pivot_index = quickSortInplacePartition(arr, start, end); 
    quickSort(arr, start, pivot_index-1);    
    quickSort(arr, pivot_index+1, end);       
  }
}

void bucketSort(int *arr, int n, int range){
  int bucket[range];
  for(int i =0;i < range; i++){
    bucket[i] = 0;
  }
  for(int i = 0; i<n; i++){
    bucket[arr[i]]++;
  }  
  int k = 0;
  for(int i = 0; i<range; i++){
    if(bucket[i]!=0){
      int count = bucket[i];
      while(count--){
        arr[k] = i;
        k++;
      }
    }
  }
  
}
int main(void) {
  int n = 15;
  int arr1[]= {-26,-80,-50,41,9,-66,1,-76,14,-39,68,-4,-51,-79,77};
  int arr2[]= {-26,-80,-50,41,9,-66,1,-76,14,-39,68,-4,-51,-79,77};
  int arr3[]= {-26,-80,-50,41,9,-66,1,-76,14,-39,68,-4,-51,-79,77};
  int arr4[]= {-26,-80,-50,41,9,-66,1,-76,14,-39,68,-4,-51,-79,77};
  int arr5[]= {-26,-80,-50,41,9,-66,1,-76,14,-39,68,-4,-51,-79,77};
  int arr6[]= {0,12,11,7,5,4,18,3,3,2,2,1,12,13,14,5,0,19,12,17,9,18,18,19};


  printf("Bubble Sort - \n");
  bubbleSort(arr1, n);  
  print_array(arr1, n);
  printf("\n\n");


  printf("Insertion Sort - \n");
  insertionSort(arr2, n);
  print_array(arr2, n);
  printf("\n\n");


  printf("Merge Sort - \n");
  mergeSort(arr3,0,n-1);
  print_array(arr3, n);
  printf("\n\n");

  printf("Quick Sort - \n");
  quickSort(arr4, 0, n-1);
  print_array(arr4, n);
  printf("\n\n");

  printf("Selection Sort - \n");
  selectionSort(arr5, n);
  print_array(arr5, n);
  printf("\n\n");

  printf("Bucket Sort - \n");
  bucketSort(arr6, 24, 20);
  print_array(arr6, 24);
  printf("\n\n");



  return 0;
}

