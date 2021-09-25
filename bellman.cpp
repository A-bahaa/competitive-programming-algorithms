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


//this implementation only detects if there is a negative cycle in the graph and returns the shortest distance between the source and target only if there's no negative cycles .


//BF Algorithm steps
/*
1- set the distance to each node to +infinity
2- set the distance of the src to 0
3- relax each edge n-1 (maximum) times
*/



int n , m ;
vector<pair<int,pair<int,int>>> edges;

pair<bool,int>bellman(int src , int tar){
    vector<int>dis(n,OO);
    dis[src]= 0;
    bool hasNegativeCycle = 0;
    //I know we should relax n-1 times but in this implementaion we relax n times to see if any updates happen in the nth iteration because that means existence of negative cycles .
    for(int i = 1; i<=n; i++){
        bool anyUpdates = 0;
        for(auto e : edges){
            if(dis[e.to]>dis[e.from]+e.cost){
                dis[e.to] = dis[e.from]+e.cost;
                anyUpdates = 1;
            }
        }
        //the stopping-early optmization
        if(!anyUpdates)break;
        //if there's updates in the nth cycle
        else if(i==n){
            hasNegativeCycle = 1;
        }
    }
    return {hasNegativeCycle,dis[tar]};

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
    pair<bool,int>ans = bellman(--src,--tar);
    if(ans.first){
        cout<<"The graph has negative cycles \n";
    }
    else{
        cout<<"there's no negative cycle and the shortest distance is "<<ans.second<<'\n';
    }
    return 0;
}


