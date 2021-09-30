#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


// supose the coins we have are 1,5,10,25 and 50 cents . 

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int sum; cin>>sum;
    //every cell (i,j) holds the answer for the following subproblem ..
    //with "i" number of coins what are the different ways to make a total of j
    vector<vector<int>>T(6,vector<int>(sum+1,0));
    //the coins have to be sorted .
    //the first coin is 0 just for the sake of one basing
    vector<int> coins = {0,1,5,10,25,50};
    // because there's only one way to make 0 sum from 0 number of coins
    T[0][0] = 1;
    for(int i = 1; i<=5; i++){
        for(int j = 0; j<=sum; j++){
            // if the current column weight is less than the new coin-weight introduced in this row , we exclude this coin and the sub-problem transferes to "with "i-1" number of coins what are the different ways to make a total of j" which basically the same as the cell above your current cell .
            if(j<coins[i]){
                T[i][j] = T[i-1][j];
            }
            // else the number of ways is equal to the result of two sub-problems : (the excluding subproblem , the same as before) + (the including subproblem => the answer to this subproblem is equal to the answer of "with "i" number of coins what are the different ways to make a total of j-coins[i]" .
            else{
                T[i][j] = T[i-1][j] + T[i][j-coins[i]];
            }
        }
    }
    // the answer to the original problem can be found in the T[5][sum] cell
    cout<<T[5][sum]<<'\n';
    return 0;
}