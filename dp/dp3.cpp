//LONGEST COMMON SUBSEQUENCE
#include <bits/stdc++.h>
using namespace std;

int main(){
    string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string B = "BHIPTUXY";
    int N = A.size();
    int M = B.size();
    int dp[N+1][M+1];
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=M;j++){
            dp[i][j] = 0;
        }    
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1;j<=M;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];            
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
            }

            //cout << dp[i][j] << endl;
        }
    }/*

    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=M;j++){
            cout << dp[i][j] << " ";
        }    
        cout << endl;
    } */
    int i = N;
    int j = M;
    while(i>=0 && j>=0){
        if(i==0 || j==0){            
            //cout << "(" << i<< "," << j << ")" << endl; 
            break;
        } else {
            if(dp[i][j]==1+dp[i-1][j-1]){
               // cout << "(" << i<< "," << j << ")" << endl; 
               cout << B[j-1];
                i--;
                j--;
            } else if (dp[i][j]==dp[i-1][j]){
                i--;
            } else {
                j--;
            }
        }
    }

    cout << endl;

    cout << dp[N][M] << endl;
    return 0;
}