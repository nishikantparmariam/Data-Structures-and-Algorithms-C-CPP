//LONGEST CONSECUTIVE INTEGER SEQUENCE
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {11,10,1,4,12,2,3,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int, int> dp;
    for(int i = 0;i<N;i++){
        dp[arr[i]]++;
    }


    int ans = INT_MIN;
    for(int i = 0; i<N; i++){
        if(dp.find(arr[i]-1)==dp.end()){
            int j = 0;
            while(dp.find(arr[i]+j)!=dp.end()){
                j++;
            }
            ans = max(ans, j);
        }
    }
    
    cout << endl;
    cout << ans << endl;
    return 0;
}