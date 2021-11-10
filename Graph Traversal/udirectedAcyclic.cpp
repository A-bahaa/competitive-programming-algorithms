#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


bool Acyclic;
vector<vi>adj;
vector<bool>visited;


void DFS (int s , int parent){

    visited[s]=1;
    for(int i : adj[s]){
        if(!visited[i]){
            DFS(i , s);
        }
        else if (i==parent)continue;
        // if a node has a child that's visited and it's not its directed parent in an undirected graph , then the graph contains a cycle .
        else Acyclic = 0;    
    }
    
}




int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t; 
    while(t--){
        // in-case of multiple cases 
        adj.clear();
        visited.clear();
        
        Acyclic = 1;
        
        int n , m; cin>>n>>m;
        adj.resize(n);
        visited.resize(n,0);
        
        
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            // zero-basing
            adj[--u].push_back(--v);
            adj[v].push_back(u);
            
        }
        for(int i =0; i <n; i++){
            if(visited[i]==0){
                // the first call in each component will be with an imaginary parent
                DFS(i,-1);
            }
        }
        if(Acyclic)cout<<"the graph contains no cycles\n";
        else cout<<"the graph contains cycles\n";

    }
    return 0;
}
