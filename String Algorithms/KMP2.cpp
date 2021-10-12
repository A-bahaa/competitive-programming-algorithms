#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f;



int main (){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // another implementation to the KMP algo by creating the prefix vector for the strring "patt+$+s" the middle character has not to be found in s or patt .

    
    string patt , s ; cin>>s>>patt;
    int iniSize = patt.size();
    patt = patt+'$'+s;
    vi pf(patt.size() , 0);
    int i = 1 , j = 0;
    while(i<patt.size()){
        if(patt[i]==patt[j]){
            pf[i] = j+1;
            i++ ; j++;
        }
        else if(j==0){
            // if there's a mis-match and j == 0 that means we couldn't find any prefix that ends with the letter patt[i] so we put 0 in the pf vector and move on . 
            pf[i] = 0;
            i++;
        }
        else{
            // if there's no match we go to the end of the previous longest common prefix and suffix trying to append the letter patt[i] .
            j = pf[j-1];
        }
    }
    //for(int i : pf)cout<<i<<' ';
    for(int i = 0; i<patt.size(); i++){
        // if it's equal the size of the original patt 
        if(pf[i] == iniSize){
            cout<<i-(2*iniSize)<<' ';
        }
    }
    return 0;
}
