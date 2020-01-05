//DISC STCKING
#include <bits/stdc++.h>
using namespace std;

int K, n;

int dp[100][100][100];

int go(int i, int m, int k){

    

    if(dp[i][m][k]!=-1) return dp[i][m][k];
        
    if(i==n){
        if(m<0){
            dp[i][m][k] = 0;
            return dp[i][m][k];
        } else {
            dp[i][m][k] = 1;
            return dp[i][m][k];
        }
    } else if(i!=n && m==0){
        dp[i][m][k] = 0;
        return dp[i][m][k];
    } else  {
        if(k==0){
            dp[i][m][k] =  go(i, m-1, K);
            return dp[i][m][k];
        } else {           

            dp[i][m][k] =  go(i+1,m,k-1)+go(i, m-1, K);
            return dp[i][m][k];
        }
    }
    
}

int main(){

    for(int i = 0;i<100;i++){
        for(int j =0;j<100;j++){
            for(int k=0;k<100;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    n = 70;
    int m = 10;
    K = 10;    

    cout << go(0, m, K) << endl;
    
    return 0;
}