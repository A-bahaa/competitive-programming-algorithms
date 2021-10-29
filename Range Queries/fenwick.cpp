#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 



int n; 
vi arr;
vector<ll>bit; //short for binary-indexed-tree


// when the value at index idx gets updated , all its children gets updated too . That takes O(log(n)) . 
void update(int idx , int chang){
    for(int i = idx; i<=n; i+=(i&-i)){
        bit[i]+=chang;
    }
}

// building the fenwick tree for the first time takes O(nlogn) . 
void build(){
    bit = vector<ll>(n+1,0);
    for(int i = 1; i<=n; i++){
        update(i , arr[i]);
    }
}
/*
there's another implementation of the build() that runs in O(n) :

void build(){
    // copying the initial values in the bit .
    bit  = Arrays.copyOf(arr,arr.size());
    for(int i = 1; i<=n; i++){
        int p = i + (i&-i); // index of the immediate parent range
        if(p<=n){
            bit[p]+=bit[i];
        }
    }

}

*/
 
ll prefixSum(int indx){
    ll sum=0;
    // marching backwards to all the powers of 2 that make indx .
    for(int i=indx; i>=1; i-=(i & -i))
        sum+=bit[i];
    return sum;
}

ll rangeSum(int l, int r){
    return prefixSum(r)-prefixSum(l-1);
}



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    arr=vector<int>(n+1);
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    build();
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            cout<<rangeSum(l,r)<<'\n';
        }
        else{
            int indx,newVal;
            cin>>indx>>newVal;
            update(indx,newVal-arr[indx]);
        }
    }
 
    return 0; 
}




  