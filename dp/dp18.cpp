//MAXIMUM SUM INCREASING SUBSEQUENCE
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,101,2,3,100,4,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    int dp[N];
    for(int i = 0;i<N;i++) dp[i] = arr[i];
    for(int j = 1; j<N;j++){
        for(int i = 0;i<j;i++){
            if(arr[i]<=arr[j]){
                dp[j] = max(dp[j], arr[j]+dp[i]);
            }
        }        
    }
    for(int i = 0; i<N; i++) cout << dp[i] << " ";
    return 0;
}