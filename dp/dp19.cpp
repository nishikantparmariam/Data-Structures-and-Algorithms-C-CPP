//BOX STACKING
#include <bits/stdc++.h>
using namespace std;

struct myComp {
    bool operator()(const vector<int> &a, const vector<int> &b){
        return (a[1]*a[2] < b[1]*b[2]);
    }
};

bool myCompFunc(const vector<int> &a, const vector<int> &b){
        return (a[1]*a[2] < b[1]*b[2]);
}

int main(){
    vector<vector<int>> A = {{8, 8, 3},{8, 8, 8},{15, 4, 3},{3, 13, 12}};
    vector<vector<int>> A_new;    
    for(int i=0;i<A.end()-A.begin();i++){
        int h = A[i][0];
        int w = A[i][1];
        int l = A[i][2];              
        A_new.push_back(vector<int>({h,w,l}));        
        A_new.push_back(vector<int>({h,l,w}));        
        A_new.push_back(vector<int>({l,w,h}));        
        A_new.push_back(vector<int>({l,h,w}));        
        A_new.push_back(vector<int>({w,h,l}));        
        A_new.push_back(vector<int>({w,l,h}));        
    }
    
    int N = A_new.size();
    sort(A_new.begin(), A_new.end(), myCompFunc);
    int mhs[N];
    int k = 0;
    for(auto it=A_new.begin(); it!=A_new.end(); it++){
        mhs[k] = (*it)[0];
        k++;
    }
    int i = 0;
    int ans = mhs[0];

    for(auto it=A_new.begin(); it!=A_new.end(); it++){
        
        int w_i = (*it)[1];
        int l_i = (*it)[2];
        int h_i = (*it)[0];        
        if(i!=0){
            int j = 0;
            for(auto it2 = A_new.begin(); it2!=it; it2++){
                int w = (*it2)[1];
                int l = (*it2)[2];                
                if(w_i > w && l_i > l){
                    mhs[i] = max(mhs[i], mhs[j]+h_i);
                }
                j++;
            }
        }
        ans = max(ans, mhs[i]);               
        i++;

    }

    cout << ans << endl;
    
    return 0;
}