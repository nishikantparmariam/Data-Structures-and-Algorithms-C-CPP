//EDIT DISTANCE
#include <bits/stdc++.h>
using namespace std;

int min_(int a, int b, int c){
    return min(a, min(b,c));
}

int main(){
    string B = "XYZ";
    string A = "ABC";
    int N = A.size();
    int M = B.size();
    int dp[N+1][M+1];
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=M; j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else {
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1+min_(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
    }

    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=M; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[N][M] << endl;
    return 0;
}