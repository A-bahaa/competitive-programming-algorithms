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
    //every cell (i,j) holds the answer for the following subproblem ..
    //what is the LCS between the first 'i' characters from s1 and the first
    // 'j' characters from s2 .
    vector<vector<int>>T(s1.size(),vector<int>(s2.size(),0));
    for(int i = 1; i<s1.size(); i++){
        for(int j = 1; j<s2.size(); j++){
            // if the two characters match , we know for sure that we've a common-
            // subsequence of lenght 1 .. hence the total answer is 1 + the answer if we deleted both characters 
            //which is memorized in the cell T[i-1][j-1] 
            if(s1[i]==s2[j]){
                T[i][j] = 1 + T[i-1][j-1];
            }
            //if they don't match we try deleting each character and maximizing between the two answers yielded in these two scenarios
            else{
                T[i][j] = max(T[i-1][j],T[i][j-1]);
            }
        }
    }
    cout<<T[s1.size()-1][s2.size()-1]<<'\n';
    //printing the dp table
    for(auto v : T){
        for(auto i :v){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    // to get the actual LCS
    int i = s1.size()-1 , j = s2.size()-1;
    string  LCS ;
    while(T[i][j] != 0){
        if(T[i][j] == T[i][j-1]){
            j--;
        }
        else if (T[i][j] == T[i-1][j]){
            i--;
        }
        else{
            LCS = s1[i]+LCS; //or LCS += s2[j] they're the same char
            i--; j--;
        }

        
    }
    cout<<LCS<<'\n';



    return 0;
}
