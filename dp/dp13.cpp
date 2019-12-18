//COIN CHANGE PROBLEM
#include <bits/stdc++.h>
using namespace std;


int main(){
    int coins[] = {25, 5, 10};
    int V = 30;
    int N = sizeof(coins)/sizeof(coins[0]);
    
    int dp[V+1][N+1];
    int table[V+1];
    table[0] = 0;
    for(int i = 1;i<=V; i++) table[i] = INT_MAX;

    for(int i = 0; i<=V; i++){
        for(int j = 0; j<=N; j++){
            if(i==0) dp[i][j] = 0;
            else if(j==0) dp[i][j] = -1;
            else if(i<coins[j-1]) dp[i][j] = dp[i][j-1];
            else {
                int remainder = i%coins[j-1];
                int divisor = i/coins[j-1];
                int minCoins = -1;
                for(int p = remainder; p<=i; p=p+coins[j-1]){
                    if(dp[p][j-1]!=-1){
                        if(minCoins==-1){
                            minCoins = dp[p][j-1]+divisor;
                        } else {
                            minCoins = min(dp[p][j-1]+divisor, minCoins);
                        }                        
                    }
                    divisor--;
                }
                dp[i][j] = minCoins;
            }
            cout << dp[i][j] << " ";

            if(j!=N){
                if(i>=coins[j]){
                    if(table[i-coins[j]]!=INT_MAX){
                        table[i] = min(table[i], 1+table[i-coins[j]]);
                    }                    
                }
            }
        
        }
    
        cout << endl;
    }

    for(int i = 0; i<=V; i++){
        if(table[i]==INT_MAX){
            cout << "NA\n";
        } else {
            cout << table[i] << "\n";
        }
        //cout << ((table[i] == INT_MAX) ? ("NA") : (table[i])) << "\t";
    }

    return 0;
}