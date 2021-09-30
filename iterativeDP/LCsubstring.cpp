#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 



int main (){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s1 , s2 ; cin>>s1>>s2;
    // just for the sake of 1 basing
    s1 = '0'+s1; s2 = '0'+s2;
    // initializing the table
    vector<vector<int>>T(s1.size(),vector<int>(s2.size(),0));
    for(int i = 1; i<s1.size(); i++){
        for(int j = 1; j<s2.size(); j++){
            if(s1[i]==s2[j]){
                T[i][j] = 1 + T[i-1][j-1];
            }
        }
    }


    //printing the dp table
    for(auto v : T){
        for(auto i :v){
            cout<<i<<' ';
        }
        cout<<'\n';
    }


    // to get the answer we have to loop through the entire table 
    int r , maxi = -1;
    for(int i = 1; i<s1.size(); i++){
        for(int j = 1; j<s2.size(); j++){
            if(T[i][j]>maxi){
                maxi = T[i][j];
                r = i ;
            }
        }
    }
    string LCS = "";
    for(int i = 0; i<maxi; i++){
        LCS = s1[r]+LCS;
        //moving diagonally
        r--;
    }
    
    cout<<"the length of the longest common substring is "<<maxi<<" and it's "<<LCS<<'\n';

        
    
   
    return 0;
}