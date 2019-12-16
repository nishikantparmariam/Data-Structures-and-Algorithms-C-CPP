//LONGEST BITONIC SUBSEQUENCE
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int N = sizeof(arr)/sizeof(arr[0]);
    //LIS //ending at index 
    int lis[N];
    for(int i = 0; i<N; i++) lis[i] = 1;
    for(int j = 1; j<N; j++){
        for(int i=0; i<j; i++){
            if(arr[i]<arr[j]) lis[j] = max(lis[j], 1+lis[i]);
        }
    }


    //LIS
    int lds[N]; //starting at index
    for(int i = 0; i<N; i++) lds[i] = 1;
    for(int j = N-2; j>=0; j--){
        for(int i=j+1; i>j; i--){
            if(arr[i]<arr[j]) lds[j] = max(lds[j], 1+lds[i]);
        }
    }

    int ans = -1;
    for(int i = 0;i<N;i++){
       // cout << lds[i] << "--" << lis[i] << endl;
        ans = max(ans, lds[i]+lis[i]-1); 
    }

    cout << ans << endl;

    return 0;
}