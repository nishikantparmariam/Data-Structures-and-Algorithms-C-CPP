//LONGEST PALINDROMIC SUBSEQUENCE
#include <bits/stdc++.h>
using namespace std;

int go(int i, int j, string S){
    //cout << i << "--" << j << endl;
    if(i>j) return 0;
    if(i==j) return 1;
    if(S[i]==S[j]) return 2+go(i+1,j-1,S);
    return max(go(i+1,j,S), go(i,j-1,S));
}

int main(){
    string S = "ABCDXMNEFGHIJKLNMX";
    int N = S.size();
    cout << go(0, N, S) << endl;

    int dp[N][N];
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N;j++){
            if(i==j) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }

    for(int gap = 0; gap<N; gap++){
        int j = N-1;
        int i = j-gap;
        while(i>=0){
            cout << i << "--" << j << endl;
            if(i==j) dp[i][j] = 1;
            else if(S[i]==S[j]) dp[i][j] = 2+dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            j--;
            i--;
        }
        cout << endl << endl;
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << dp[i][j] << " ";
        }       
        cout << endl;
    }    
    return 0;
}