//LONGEST CHAIN SUBSET
#include <bits/stdc++.h>
using namespace std;
int comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first==p2.first){
        return p1.second <= p2.second;
    } 
    return p1.first <= p2.first;
}

int main(){
    pair<int,int> arr[] = {make_pair(5,24), make_pair(15,25), make_pair(27,40), make_pair(27, 28), make_pair(50,60)};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, arr+N, comp);
    for(int i = 0; i<N; i++){
        cout << arr[i].first << "--" << arr[i].second << endl;
    }
    cout << endl; 

    int lis[N];
    for(int i = 0; i<N; i++){
        lis[i] = 1;
    }

    for(int i = 1; i<N; i++){
        for(int j = 0; j<i; j++){
            if(arr[j].second <= arr[i].first){
                lis[i] = max(lis[i], 1+lis[j]);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i<N; i++){
        cout << lis[i] << "\t";
        ans = max(ans, lis[i]);
    }
    cout << endl;

    cout <<ans << endl;
    return 0;
}