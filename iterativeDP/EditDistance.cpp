#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    string s1 , s2; cin>>s1>>s2;

    // one basing
    s1 = '0'+s1; s2 = '0'+s2;

    vector<vector<int>>T(s2.size()+1,vector<int>(s1.size()+1,0));

    for(int i = 0; i<=s2.size(); i++){
        for(int j = 0; j<=s1.size(); j++){
            if(i==0 || j==0){
                T[i][j]=max(i,j);
            }
            else if (s1[j] == s2[i]){
                T[i][j]=T[i-1][j-1];
            }
            else {
                T[i][j] = 1+min(T[i-1][j-1] , min(T[i-1][j] , T[i][j-1]));
            }
        }
    }
    
    cout<<T[s2.size()][s1.size()]<<'\n';
    
    return 0;
}