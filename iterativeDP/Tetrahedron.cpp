#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

 

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n ; cin>>n;
    vector<vector<ll>>T(2,vector<ll>(n+1 , 0));
    T[1][0] = 1;
    for(int j = 1; j<=n; j++){
        T[1][j] = 3*T[0][j-1]%M;
        T[0][j] = (2*T[0][j-1] + T[1][j-1])%M;
    }
    //because the ant'll start at the top and has to complete exactly n steps
    cout<<T[1][n];

       
    return 0;
}
