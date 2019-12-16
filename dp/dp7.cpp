//EGG DROPPING PROBLEM
#include <bits/stdc++.h>
using namespace std;

//n - no. of floors
//k - no. of eggs


int go(int n, int k){

    //cout << n << "--" << k << endl;
    if(n==0 || n==1 || k==1) return n;
    //if(k==1) return n;
    
    int min_ans = INT_MAX;
    for(int i = 1; i<=n; i++){
        min_ans = min(min_ans, max(go(i-1,k-1),go(n-i,k)));
    }
    return min_ans+1;

}


int main(){

    int floors = 10;
    int eggs = 2;

    int dp[floors+1][eggs+1];
    for(int floor = 0; floor<=floors; floor++){
        for(int egg = 0; egg<=eggs; egg++){
            if(floor==0) dp[floor][egg] = 0;
            else if(egg ==0) dp[floor][egg] = 0;
            else if(egg==1) dp[floor][egg] = floor;
            else {
                int min_ = INT_MAX;
                for(int x = 1; x<=floor; x++){
                    min_ = min(min_, max(dp[x-1][egg-1], dp[floor-x][egg]));
                }
                dp[floor][egg] = 1+min_;
            }

            cout << dp[floor][egg] << " ";            
        }

        cout << endl;
    }



    cout << go(10, 2) << endl;
    return 0;
}