#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;

vector<vi>adj;
vector<bool>visited , instack;
stack<int> ans;
bool Acyclic = true;

void topSort (int s){
    visited[s]=1;
    instack[s]=1;
    for(int i : adj[s]){
        if(!visited[i]){
            topSort(i);
        }
        else if(instack[i]==1)Acyclic=false;
    }
    ans.push(s);
    instack[s]=0;

}


 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        
    

    int n , m;
    while(cin>>n>>m , n||m){

        
        Acyclic = 1;
        adj.clear();
        visited.clear();
        instack.clear();
        // stack ans evacuated
        stack<int>emp;
        ans.swap(emp);
        
        
        visited.resize(n,0);
        instack.resize(n,0);
        adj.resize(n);
       
        
        for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[--u].push_back(--v);
        
        }
        
        for(int i =0; i <n; i++){
        if(visited[i]==0){
            topSort(i);
        }
    }

    if(!Acyclic)cout<<"IMPOSSIBLE\n";
    else{
        while(!ans.empty()){
            cout<<++ans.top()<<'\n';
            ans.pop();
        }
    }
    }


    return 0; 
}     



 