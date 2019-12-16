//LARGEST SUM SUBSEQUENCE/KADANE'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int N = sizeof(arr)/sizeof(arr[0]);
    //Kadane's Algorithm

    int max_so_far = -INT_MAX;
    int max_ending_here = -INT_MAX;
    
    stack<int> start_here;
    stack<int> ends_here;

    start_here.push(0);
    ends_here.push(N-1); 

    for(int i = 0; i<N; i++){
        
        if(max_ending_here < 0){
            max_ending_here = arr[i];                        
            start_here.push(i);
        } else {
            max_ending_here+=arr[i];           
            ends_here.push(i);
        }       

        max_so_far = max(max_so_far, max_ending_here);
    }

    cout << max_so_far << endl;

    cout << start_here.top() << "--" << ends_here.top() << endl;    
    return 0;
}