//FIBONACCI NUMBERS
#include <bits/stdc++.h>
using namespace std;

int fib(int n, int *lookup){
    if(lookup[n]!=-1){
        return lookup[n];
    } else {
        if(n==0){
            lookup[n] = 0;
            return lookup[n];
        } else if(n==1){
            lookup[n] = 1;
            return lookup[n];
        } else {
            lookup[n] = fib(n-1, lookup)+fib(n-2, lookup);
            return lookup[n];
        }
    }
}


int main(){
    while(1){
        int n;
        cin >> n;
        int lookup[n+1];
        for(int i = 0; i<=n; i++){
            lookup[i] = -1;
        }

        int lookup2[n+1];
        for(int i = 0; i<=n; i++){
            if(i==0) lookup2[i] = 0;
            else if(i==1) lookup2[i] = 1;
            else lookup2[i] =  lookup2[i-2]+lookup2[i-1];
        }
        cout << fib(n, lookup) << endl;
        cout << lookup2[n] << endl;
    }    
    return 0;
}