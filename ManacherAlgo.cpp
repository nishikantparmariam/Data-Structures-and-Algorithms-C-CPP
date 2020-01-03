#include <bits/stdc++.h>
using namespace std;

//MANACHER'S ALGO

string stringProcessing(string S){
    char hash = '#';
    string toReturn = "#";
    for(int i=0;i<S.size();i++){
        toReturn=toReturn+S[i]+"#";
    }
    return toReturn;
}

int main(){
    string S = "ABCBCBAGUESEUSAB";
    string A = stringProcessing(S);
    int n = A.size();
    int lps[n];
    for(int i=0;i<n;i++) lps[i] = 0;
    int center = 0;
    int right = 0;
    for(int i = 0;i<n;i++){
        //cout << center << " ";
        int i_mirror_left = center-(i-center);
        if(i<right){
            lps[i] = min(right-i,lps[i_mirror_left]);
        } 

        while(A[i+1+lps[i]]==A[i-1-lps[i]]){
            lps[i]++;
        }

        if(i+lps[i]>right){
            right = i+lps[i];
            center = i;
        }        

        cout << lps[i] << " ";
    }
    return 0;
}