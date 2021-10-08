#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f;

// this implementation of Rabin-Karp uses pushFront and popBack functions .

ll egcd(ll a, ll b, ll &x, ll &y){ /// ax + by = gcd(a,b)
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll g=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
 
ll modInverse(ll a, ll m){ /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x,y,g;
    g=egcd(a,m,x,y);
    if(g>1)
        return -1;
    return (x+m)%m;
}


ll fixMod(ll a, ll m){
    return (a + m)%m;
}

ll pushFront(ll h, ll xp, ll p, char ch){ // xp=XP[len]
    return (h+(xp*ch)%p)%p;
}

ll popBack(ll h, ll x, ll p, char ch){
    return (fixMod(h-ch,p)*modInverse(x,p))%p;
}





int main(){

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //to reduce hash-values collisions we pick the multiplier-constant to be higher than the biggest number in the alphabet (the scope in this problem) . 

    ll x=128, p1=1e9+7, p2=1e9+9;
    // reprocessing all the power values to get x^len(patt)-1 in O(1) , so the rolling-hash can be achieved in O(1) .
    // we might've several queries , so we'll reprocess the powers up to the longest pattern size .. usually 1e5 or 1e6
    vector<ll>XP1(1e6+1),XP2(1e6+1);
    XP1[0]=XP2[0]=1;
    for(int i=1; i<=1000000; i++){
        XP1[i]=(XP1[i-1]*x)%p1;
        XP2[i]=(XP2[i-1]*x)%p2;
    }

    int t; cin>>t;
    while(t--){
        string s , patt; cin>>s>>patt;
        int n = s.size() , m = patt.size();
        ll hpatt1 = 0 , hpatt2 = 0;
        for(int i = m-1; i>=0; i--){
            hpatt1 = pushFront(hpatt1 , XP1[m-i-1] , p1 , patt[i]);
            hpatt2 = pushFront(hpatt2 , XP2[m-i-1] , p2 , patt[i]);
        }
        // i<min(n,m) because the pattern might be longer than the string s , so if we didn't handle it we get index-out of bounds error .
        ll hs1 = 0 , hs2 = 0;
        for(int i  = n-1; i>=n-m; i--){
            hs1 = pushFront(hs1 , XP1[n-i-1] , p1 , s[i]);
            hs2 = pushFront(hs2 , XP2[n-i-1] , p2 , s[i]);
        }
        stack<int>ans;
        // if we got a match at the first window
        if(hpatt1 == hs1 && hpatt2 == hs2)ans.push(n-m+1);

        for(int i = n-m-1 ; i>=0; i--){
            hs1 = popBack(hs1 , x , p1 , s[i+m]);
            hs2 = popBack(hs2 , x , p2 , s[i+m]);
            hs1 = pushFront(hs1 , XP1[m-1] , p1 , s[i]);
            hs2 = pushFront(hs2 , XP2[m-1] , p2 , s[i]);
            // if the two hashes values are equal then we push the index of the beginning of the occurrence in the ans vector
            if(hs1==hpatt1 && hs2==hpatt2)ans.push(i+1);
        }
        if(ans.empty()) cout<<"Not Found\n\n";
        else{
            cout<<ans.size()<<'\n';
            while (!ans.empty())
            {
                cout<<ans.top()<<' ';
                ans.pop();
            }
        
            cout<<"\n\n";
        }
    
    }

    return 0;
}