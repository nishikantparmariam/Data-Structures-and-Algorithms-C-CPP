#include <iostream>
#include <queue>
#include <vector>
#define INF 99999
using namespace std;

class myComp{
    public:
    int operator() (pair<int,int> p1, pair<int,int> p2 ){
        return p1.second > p2.second;
    }
};

void primsAlgoMST(vector<pair<int,int>> adjList[], int V){
    priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> MinHeap;  // (key, vertex)    
    bool inMST[V];
    int key[V];
    int parent[V];
    for(int i = 0; i<V; i++){
        MinHeap.push(make_pair(i, INF));
        inMST[i] = false;
        key[i] = INF;
        parent[i] = -1;
    }

    MinHeap.push(make_pair(0, 0));
    inMST[0] = true;
    key[0] = 0;
    while(!MinHeap.empty()){
        int minV = MinHeap.top().first;
        MinHeap.pop();        
        for(pair<int,int> edge_pair:adjList[minV]){            
            int v = edge_pair.first;
            int weight = edge_pair.second;            
            if(!inMST[v]){
                if(key[v]>weight){
                    key[v] = weight;
                    parent[v] = minV;
                    MinHeap.push(make_pair(v, key[v]));
                }
            }
        }


        inMST[minV] = true;        
    }

    for(int i = 0; i<V; i++){
        cout << i << " " << parent[i] << endl;
    }

}

int main(){
    int V;cin >> V;
    vector<pair<int,int>> adjList[V]; // (vertex, weight)
    int E; cin >>E;
    while(E--){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        //0-based indexing 
        adjList[v1].push_back(make_pair(v2, w));
        adjList[v2].push_back(make_pair(v1, w));
        
    }
    

    primsAlgoMST(adjList, V);
    return 0;
}