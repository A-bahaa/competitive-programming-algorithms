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
    //because I'll only deal with parents , I'll make use of the parameters variables instead of initializing new ones
    fi = findParent(fi);
    se = findParent(se);

    if(fi != se){
        //to keep it balanced
        if(sz[fi]>sz[se]){
            swap(fi,se);
        }
        parent[fi]=se;
        sz[se]+= sz[fi];
    }
}








int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n , m; cin>>n>>m;
    parent.resize(n);
    iota(parent.begin(),parent.end(),0);
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

