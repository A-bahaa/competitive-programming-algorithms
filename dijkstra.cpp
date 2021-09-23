#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

int n , m;
vector<vector<pair<int,int>>>adj;
map<int,int>path;

int dijkstra (int src , int tar){
    vi dis(n,OO);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    //the cost to reach the src node is 0 unless said otherwise
    dis[src]=0;
    q.push({0,src});
    while(!q.empty()){
        //the next-most promising node
        int u=q.top().second;
        int c=q.top().first;
        //trcing
        cout<<"now at "<<u+1<<" that has cost "<<c<<" and its value in the dis array "<<dis[u]<<'\n';
        q.pop();
        if(u==tar)
            return c;
        //if the cost of the current node not equal it's value in the dis array , that's mean we've already reached that node with a shorter path se we'll skip that pair .
        //if we removed that condition , it wouldn't affect the answer but would affect the time .
        if(c!=dis[u]){
            //trcing
            cout<<"skip this \n";
            continue;
        }

        for(auto p : adj[u]){
            int v=p.second;
            int vc=p.first;
            //tracing
            cout<<"adj "<<v+1<<" with edge "<<vc<<'\n';
            if(dis[v]>dis[u]+vc){
                dis[v]=dis[u]+vc;
                q.push({dis[v],v});
                path[v] = u;
                cout<<"the new cost to reach "<<v+1<<" is "<<dis[v]<<"\n";
            }
            else{
                cout<<"the old way better \n";

            }
        }
    }
    //reaching this return st. means ther's no path between the src and the tar points . 
    return -1;
}


int main(){

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<m; i++){
        int u , v , c;
        cin>>u>>v>>c;
        //zero basing
        --u; --v;
        adj[u].pb({c,v});
        //if it's an undirected graph
        //adj[v].pb({c,u});
    }
    int src , tar ;
    cin>>src>>tar;
    int ans=dijkstra(--src, --tar);
    if(ans==-1)
        cout<<"NO\n";
    else{
        cout<<ans<<'\n';
        //printing the path
        stack<int>sk;
        sk.push(tar);
        int i = tar;
        while(i!=src){
            sk.push(path[i]);
            i = path[i];
        }
        while(!sk.empty()){
            cout<<sk.top()<<' ';
            sk.pop();
        }
    }
    
    return 0; 

}
