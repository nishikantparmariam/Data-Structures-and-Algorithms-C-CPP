//CALCULATING NCR
#include <bits/stdc++.h>
using namespace std;

int nCr_space(int n, int r){
    int dp[r+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i<=n; i++){
        for(int j = min(r,i); j>=0; j--){
            if(i==j || j==0) {
                dp[j] = 1;
                //cout << dp[j] << " ";
            }
            else {
                dp[j] = dp[j]+dp[j-1]; 
                //cout << dp[j] << " ";
            }
        }           

    }

    cout << endl << "Space Optimized" << endl;

    for(int j = 0; j<=r; j++){
        cout << dp[j] << " ";
    }
    
    return dp[r];
}

int nCr(int n, int r){
    int dp[n+1][r+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=min(r,i); j++){
            if(i==j || j==0){
                dp[i][j] = 1;
            } else {
                dp[i][j] =  dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=min(r,i); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[n][r];
}

int main(){    
    cout << nCr(10,5) << endl;
    cout << nCr_space(10,5) << endl;
    return 0;
}