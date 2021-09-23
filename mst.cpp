#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;



int n , m;
vi parent , sz;
vector<pair<int,pair<int,int>>> edges;


int findParent(int u){
    if(parent[u]==u)return u;
    return parent[u]= findParent(parent[u]);
}


void join(int u , int v){
    u = findParent(u);
    v = findParent(v);
    if(u!=v){
        if(sz[u]>sz[v]){
            swap(u,v);
        }
        parent[u] = v;
        sz[v]+=sz[u];
    }
}

ll kruskal(){
    ll sum = 0;
    sort(edges.begin(),edges.end());
    for(pair<int,pair<int,int>> e : edges){
    
        if(findParent(e.second.first)!=findParent(e.second.second)){
            join(e.second.first,e.second.second);
            sum+=e.first;
            
        }
    }
    return sum;
}










int main(){

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    parent.clear();
    sz.clear();
    edges.clear();
    
    
    cin>>n>>m;

    parent.resize(n);
    iota(parent.begin(),parent.end(),0);
    sz.resize(n,1);

    for(int i =0; i<m; i++){
        int u , v , c;
        cin>>u>>v>>c;
        edges.pb({c,{--u,--v}});
    }
    cout<<kruskal()<<'\n';

    return 0;
}