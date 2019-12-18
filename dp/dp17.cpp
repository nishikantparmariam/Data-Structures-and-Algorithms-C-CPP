//FRIEND PAIRING PROBLEM
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 15;
    int dp[N+1];
    for(int i=0; i<=N;i++){
        if(i<=2) dp[i] = i;
        else dp[i] = dp[i-1] + (i-1)*dp[i-2];

        cout << dp[i] << " ";
    }    
    return 0;
}