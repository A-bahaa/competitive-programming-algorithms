#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 



bool isBi;
vector<vi>adj;
vector<bool>visited;
// first the colored vector is intialized with -1 meaning that the ith node hasn't yet been assigned to any color .. 
vi col;


void DFS (int s){

    
    visited[s]=true;
      
    for(int i : adj[s]){
        if(visited[i]==false){
            col[i] = !col[s];
            DFS(i);
        }
        else if(col[i]==col[s])isBi = 0;
    } 
   

}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t; 
    while(t--){
        // in-case of multiple cases 
        adj.clear();
        visited.clear();
        col.clear();
        isBi = 1;
        
        int n , m; cin>>n>>m;
        visited.resize(n,0);
        adj.resize(n);
        col.resize(n,-1);
    
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            // zero-basing
            adj[--u].push_back(--v);
            // in case of undirected graphs
            adj[v].push_back(u);
        }
        for(int i =0; i <n; i++){
            if(visited[i]==0){
                // the first node in each component gets assigned to an arbitary color 
                col[i] = 0;
                DFS(i);
            }
        }
        if(isBi)cout<<"the graph is bicolored\n";
        else cout<<"the graph isn't bicolored\n";

    }
    return 0;
}