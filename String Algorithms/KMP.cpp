#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f;



int main (){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    
    string patt , s ; cin>>s>>patt;
    // building the prefix vector
    // every cell represents the length longest common prefix and suffix ( aka border ) in the string s[0,i]
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
    vi ans;
    // pattern matching
    // i2 works as a pointer on the string s and j2 is a pointer on the pattern 
    int i2 = 0 , j2 = 0;
    while(i2<s.size()){
        if(s[i2] == patt[j2]){
            // means we caught an occurrence 
            if(j2 == patt.size()-1){
                ans.pb(i2-j2+1);
                j2 = pf[j2];
                i2++;
            }
            else{
                i2++; j2++;
            }

        }
        else if(j2 == 0)i2++;
        else j2 = pf[j-1];
    }
    for(int i : ans) cout<<i<<' ';

    return 0;
}