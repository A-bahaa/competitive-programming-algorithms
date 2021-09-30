#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


// supose the coins we have are 1,5,6 and 8 cents . 

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int sum ; cin>>sum;
    //every cell (i,j) holds the answer for the following subproblem ..
    //with "i" number of coins what are the minimum coins needed to make a total of j
    vector<vector<int>>T(5,vector<int>(sum+1,OO));
    //the coins have to be sorted .
    //the first coin is 0 just for the sake of one basing
    vector<int> coins = {0,1,5,6,8};
    // because the minimum number of coins of value 0 to sum up to 0 is actually 0
    T[0][0] = 0;

    for(int i = 1; i<=4; i++){
        for(int j = 0; j<=sum; j++){
            // if the current column weight is less than the new coin-weight introduced in this row , we exclude this coin and the sub-problem transferes to "with "i-1" number of coins what is the minimum number of coins needed to sum up to "j" are the different ways to make a total of j" which basically the same as the cell above your current cell .
            if(j<coins[i]){
                T[i][j] = T[i-1][j];
            }
            // else we minimze between two scenarios , the first is to totally ignore the new value and the problem is transfered the same way as before , the second is to pick the new value so the total number of coins in this situation is 1(the new value) + T[i][j-coins[i]] 
            else{
                T[i][j] = min(T[i-1][j] , 1+T[i][j-coins[i]]);
            }
        }
    }
    /*debugging*/
    for(auto v :T){
        for(auto i : v) cout<<i<<' ';
        cout<<"\n";
    }
    
    // the answer to the original problem can be found in the T[5][sum] cell
    //if the sum can't be obtained from the current coins like the following case : sum = 3 from coins = {2,5,7} , then the answer cell will have OO 
    if(T[4][sum]>=OO)cout<<-1<<'\n';
    else{
        cout<<T[4][sum]<<'\n';
        //you can get this optimal subset the same way as in the knapsack problem
        int i = 4 , j = sum ;
        while(T[i][j] != 0 && T[i][j] != OO){
            if(T[i][j] != T[i-1][j]){
                cout<<coins[i]<<' ';
                j -=  coins[i];
                i--;
            }
            else{
                i--;
            }
        }
    }
    
    return 0;
}