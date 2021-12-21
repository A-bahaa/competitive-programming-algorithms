#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;


vi parent , sz;


int findParent(int n){
    if(parent[n]==n) return n;
    //path compression
    return parent[n] = findParent(parent[n]);
}

void join (int fi , int se){

    fi = findParent(fi);
    se = findParent(se);
    // if they're not in the same set
    if(fi != se){
        if(sz[fi]>sz[se]){
            // to keep the graph balanced , that means to make sure every time we merge to sets the smaller set is the one the get attached to the bigger one .. that will improve the time complexity a lil bit .
            swap(fi,se);
        }
        // the union
        parent[fi]=se;
        sz[se]+= sz[fi];
    }
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n , m; cin>>n>>m;
    parent.resize(n);
    // initially each node is its own parent
    iota(parent.begin(),parent.end(),0);
    // initially the size of each set is 1 
    sz = vi(n,1);
    while(m--){
        int t,fi,se;
        cin>>t>>fi>>se;
        fi--; se--;
        if(t==1){
            join(fi,se);
        }
        else{
            if(findParent(fi)==findParent(se)){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<"\n";
            }
        }

    }


    return 0;
}

