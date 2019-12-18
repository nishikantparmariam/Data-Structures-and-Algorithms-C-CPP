//MAXIMUM AREA SQUARE/RECTANGLE IN A BINARY MATRIX
#include <bits/stdc++.h>
using namespace std;

int _min(int a,int b,int c){
    return min(a,min(b,c));
}

int valid(int h){
    if(h==0) return 1;
    return h;
}

int findMaxHistoGramArea(int *histogram, int N){
    //forward
    int forward[N];
    stack<int> forward_stack;
    for(int i = 0; i<N; i++){

        int top_index = -1;

        while(!forward_stack.empty()){
            if(histogram[forward_stack.top()] < histogram[i]) {
                top_index = forward_stack.top();
                break;
            } else {
                forward_stack.pop();
            }
        }

        forward[i] = top_index;
        forward_stack.push(i);
    }


    //backward
    int backward[N];
    stack<int> backward_stack;
    for(int i = N-1; i>=0; i--){

        int top_index = N;

        while(!backward_stack.empty()){
            if(histogram[backward_stack.top()] < histogram[i]) {
                top_index = backward_stack.top();
                break;
            } else {
                backward_stack.pop();
            }
        }

        backward[i] = top_index;
        backward_stack.push(i);
    }

    int area = -1;
    for(int i = 0;i<N;i++){
        area = max(area,histogram[i]*(backward[i]-forward[i]-1));
    }

    return area;

}

int main(){
    int N = 6; 
    int M = 5;
    int Matrix[N][M] = {{1,0,1,1,1},
                        {1,1,1,1,1},
                        {1,1,1,1,1},
                        {1,0,1,1,1},
                        {1,1,1,1,1},
                        {0,0,1,1,1}};

    //FOR SQUARE                        
    int dp_sqaure[N][M];
    for(int i = 0;i<N;i++){
        for(int j = 0; j<M; j++){
            if(i==0 || j==0) dp_sqaure[i][j] = Matrix[i][j];
            else if(Matrix[i][j]==1){
                dp_sqaure[i][j] = _min(dp_sqaure[i-1][j-1], dp_sqaure[i][j-1], dp_sqaure[i-1][j])+1;
            } else {
                dp_sqaure[i][j] = Matrix[i][j];
            }

            cout << dp_sqaure[i][j] << " ";
        }
        cout << endl;
    }

    int histogram[M];
    int maxArea = -1;
    for(int i = 0; i<N; i++){
        //build histogram
        if(i==0){
            for(int j = 0;j<M;j++) histogram[j] = Matrix[0][j];
        } else {
            for(int j = 0;j<M;j++){
                if(Matrix[i][j]==0){
                    histogram[j] = 0;
                } else {
                    histogram[j]+=Matrix[i][j];
                }
            } 
        }

        maxArea = max(maxArea, findMaxHistoGramArea(histogram, M));

    }

    cout << maxArea << endl;
    return 0;
}