#include <bits/stdc++.h>
using namespace std;



int main(){
    string S = "KK";
    int N = S.size();
    int ans = 0;
    stack<pair<int,int>> ans_stack;
    bool table[N][N];
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){            
            table[i][j] = false;
        }
    }
    for(int gap = 0; gap<N; gap++){
        int j = N-1;
        int i = j-gap;
        while(i>=0){
            if(i==j){
                table[i][j] = true;
            } else if(S[i]==S[j]) {
                if(j-i==1) table[i][j] = true;
                else table[i][j] = table[i+1][j-1];
            } else {
                table[i][j]  = false;
            }

            if(table[i][j]){
                //ans= max(ans, j-i+1);
                if(j-i+1>ans){
                    ans = j-i+1;
                    ans_stack.push(make_pair(i,j));
                }
                cout << i << "--" << j << endl;
            }
            j--;
            i--;
        }
    }

    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;
    cout << S.substr(ans_stack.top().first, ans_stack.top().second-ans_stack.top().first+1) << endl;
    return 0;
}