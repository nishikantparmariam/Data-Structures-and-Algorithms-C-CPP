//TILE PLACING PROBLEM

#include <bits/stdc++.h>
using namespace std;


int go(int i, int N, int *dp){    
    if(i==N) return 1;
    if(i==N-1) {
        if(dp[i]==-1){
            dp[i] = go(i+1,N,dp);
        }            
        return go(i+1,N,dp);
    }
    else {
        if(dp[i]==-1){
            dp[i] =go(i+1,N,dp)+go(i+2,N,dp);
        }
    }
    return dp[i]; 
}

int main(){
    int N = 10;
    int dp[N];
    for(int i = 0; i<N; i++) dp[i] = -1;
    cout << go(0, N, dp) << endl;
    return 0;
}