//LONGEST INCREASING SUBSEQUENCE
#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {10,22,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(int);    
    int dp[n];
    int ance[n];
    for(int i = 0; i<n; i++) dp[i] = 1;
    for(int i = 0; i<n; i++) ance[i] = -1;
    for(int i = 1; i<n;i++){
        for(int j = 0; j<i; j++){
            if(arr[j]<arr[i]){
                //dp[i] = max(dp[i], dp[j]+1);
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    ance[i] = j;
                }
            }
        }
    }
    int max = -1;
    int index = -1;
    for(int i = 0; i<n; i++){
        cout << dp[i] << "\t" ;
        if(max < dp[i]){
            max = dp[i];
            index = i;
        }
    }

    cout << endl;
    for(int i = 0; i<n; i++){
        cout << ance[i] << "\t" ;
    }

    cout << endl;

    while(1){
        cout << arr[index] << "\t";
        index = ance[index];
        if(index==-1) break;
    }

    return 0;
}