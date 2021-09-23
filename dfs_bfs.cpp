#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;

//todo 
/*
how to check if a graph is bi colour
topological sort

*/


vector<vi> adj;
vector <bool> visited;

int sum = 0;
vi sums;

void DFS (int s){
    visited[s]=true;
    // pre-order ops
    sum++;
     
    for(int i : adj[s]){
        if(visited[i]==false){
            DFS(i);
        }
    } 
    //post-order ops
    

}

void BFS (int s){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //pre-order ops
        cout<<u<<'\n';
        for(int i : adj[u]){
            if(visited[i]==0){
                q.push(i);
                visited[i] = 1;
            }
            
        }
    }
}













int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t; 
    while(t--){
        adj.clear();
        visited.clear();
        sums.clear();
        

    
    int n , m; cin>>n>>m;
    visited.resize(n,0);
    adj.resize(n);
    //for(auto i : visited)cout<<i<<' ';
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    for(int i =0; i <n; i++){
        if(visited[i]==0){
            DFS(i);
            sums.push_back(sum);
            //cout<<"here is the sum "<<sum<<'\n';
            sum = 0;
        }
    }
    sort(sums.begin(),sums.end(),greater<int>());
    cout<<sums[0]<<'\n';





    }
    return 0;
}

/*
7 6
0 1
0 2
2 5
1 4
1 3
4 6

*/