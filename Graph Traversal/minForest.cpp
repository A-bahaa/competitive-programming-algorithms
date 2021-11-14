#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO= - 0x3f3f3f3f; 

vector<vector<pair<int,int>>>adj;
vector<bool>visited;


pair<ll,ll> DFS(int s){
    visited[s] = 1;
    ll sum = 0 , mx = 0;
    for(auto p : adj[s]){
        int v = p.first;
        int c = p.second;
        if(visited[v]) continue;
        pair<ll,ll>child = DFS(v);
        // the total sum of the forest = the total sum of the child node + the edge between the source and the edge;
        sum += child.first + c;
        // maximazing on the maximum branch 
        mx = max(mx,child.second+c);
    }
    return {sum , mx};

}







int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n; cin>>n;

    adj.resize(n);
    visited.resize(n,0);

    for(int i = 0; i<n-1; i++){
        int u , v , c; cin>>u>>v>>c;
        adj[--u].pb({--v,c});
        adj[v].pb({u,c});
    }
    // calling from the root
    pair<ll,ll>ans = DFS(0);
    cout<<2*ans.first-ans.second;

    return 0;
}