//BEST TIME TO PURCHASE STOCK (MAX PROFIT WITH AT MOST K TRANSACTIONS)
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> prices = {84,1,10, 54, 5, 15, 65, 100};
    int n = prices.size();
    int k = 5;
    int dp[k+1][n];
    int req = 0;
    for(int t = 0;t<=k;t++){
        for(int i=0;i<n;i++){
            if(t==0 || i==0) dp[t][i] = 0;
            else if(i==1) {
                dp[t][i] = max(prices[1]-prices[0], 0);
                req = max(dp[t-1][0]-prices[0], dp[t-1][1]-prices[1]);
            } else {
                int maxHere = 0;
                for(int j=0;j<i;j++){
                    maxHere = max(maxHere, prices[i]+dp[t-1][j]-prices[j]);
                }                                    
                dp[t][i] = max(dp[t][i-1], maxHere);
                req = max(req, dp[t-1][i]-prices[i]);
            }
        }
    }

    cout << dp[k][n-1];
    return 0;
}