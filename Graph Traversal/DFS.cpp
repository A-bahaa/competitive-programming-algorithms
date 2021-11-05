#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 




vector<vi>adj;
vector<bool>visited;


void DFS (int s){

    // pre-order ops
    visited[s]=true;
      
    for(int i : adj[s]){
        if(visited[i]==false){
            DFS(i);
        }
    } 
    //post-order ops

}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t; 
    while(t--){
        // in-case of multiple cases 
        adj.clear();
        visited.clear();
        
        int n , m; cin>>n>>m;
        visited.resize(n,0);
        adj.resize(n);
    
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            // zero-basing
            adj[--u].push_back(--v);
            // in case of undirected graphs
            adj[v].push_back(u);
        }
        for(int i =0; i <n; i++){
            if(visited[i]==0){
                DFS(i);
            }
        }

    }
    return 0;
}