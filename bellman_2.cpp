#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

 
#define cost first
#define from second.first
#define to second.second


//this implementation returns -1 if the target node directly contribute to a negative cycle or rechable by a negative cycle , otherwise returns the shortest distance between the source and the target




int n , m ;
vector<pair<int,pair<int,int>>> edges;

pair<bool,int> bellman(int src , int tar){
    vector<int>dis(n,OO);
    dis[src]= 0;
    for(int i = 1; i<n; i++){
        bool anyUpdates = 0;
        for(auto e : edges){
            if(dis[e.to]>dis[e.from]+e.cost){
                dis[e.to] = dis[e.from]+e.cost;
                anyUpdates = 1;
            }
        }
        //the stopping-early optmization
        if(!anyUpdates)break;
    }
    //a boolean vector correspond to each node being in a negative cycle or not
    vector<bool>inCycle(n,0);
    for(int i = 1; i<n; i++){
        bool anyUpdates = 0;
        for(auto e : edges){
            if(dis[e.to]>dis[e.from]+e.cost){
                dis[e.to] = dis[e.from]+e.cost;
                inCycle[e.to] = 1;
                anyUpdates = 1;
            }
            /*if(inCycle[e.from]){
                inCycle[e.to] = 1;
            }*/

        }
        //the stopping-early optmization
        if(!anyUpdates)break;
    }
    
    if(inCycle[tar])return {0,-1};
    else return {1,dis[tar]};

}
        
      

int main(){

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i<m ; i++){
        int u , v , c;
        cin>>u>>v>>c;
        edges.push_back({c,{--u,--v}});
    }
    int src, tar;
    cin>>src>>tar;
    pair<bool,int> ans = bellman(--src,--tar);

    if(!ans.first){
        cout<<"the target node is in a negative cycle\n";
    }
    else cout<<ans.second<<'\n';

    return 0;
}


