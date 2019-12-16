//0/1 KNAPSACK PROBLEM
#include <bits/stdc++.h>
using namespace std;



int go(int index, int weight_now, int *value, int *weight){
    cout << "Called" << endl;
    if(index==3) return 0;
    int a = 0;
    if(weight_now-weight[index]>=0)  a = value[index]+go(index+1,weight_now-weight[index],value, weight);
    int b = go(index+1,weight_now,value, weight);
    return max(a,b);
}

int main(){

    int value[] = {60,100,120};
    int weight[] = {1,2,3};

    int W = 5;
    int n = 3;

    int dp[n+1][W+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weight[i-1]<=j){
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
                

            } else {
                dp[i][j] = dp[i-1][j];                
            }            
         }         
         cout << endl;
    }


    cout << go(0,W, value, weight) << "--" << dp[n][W] << endl;

    return 0;
}