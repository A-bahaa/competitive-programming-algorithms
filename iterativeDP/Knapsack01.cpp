#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

int main(){

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int maxW , nEle;
    cin>>maxW>>nEle;
    vector<pair<int,int>>ele;
    //because I'll access them one based
    ele.pb({0,0});
    for(int i = 0; i<nEle; i++){
        int w , val ; cin>>w>>val;
        ele.pb({w,val});
    }
    //sorting the elements in an ascending order upon their weights
    sort(ele.begin(),ele.end());


    //every cell (i , j) in this Table will hold the answer of the sub problem that is described by "if I have i elements and maximum weight of j what is the maximum value can I optain ?" .. the answers of these  subproblems will be used while looping the Table till we reach the original/desired problem "if I have nEle elements and maximum weight of maxW what is the maximum value can I optain ?" and the final answer is in the cell (nEle , maxW) .
    vector<vector<int>>T(nEle+1,vector<int>(maxW+1,0));

    /* for(auto p : ele){
        cout<<p.first<<' '<<p.second<<' ';
    } */
    /* for(auto v:T){
        for(auto i:v)cout<<i<<' ';
        cout<<'\n';
    } */
    for(int i = 1; i<=nEle; i++){
        for(int j = 1; j<=maxW; j++){
            // if the current weight can't hold the new item of this row , then we skip it so the proplem transformed to be "if I have i-1 elements and maximum weight of j what is the maximum value can I optain ?" and the answer for that is in the cell above the current location . 
            if(j<ele[i].first){
                T[i][j] = T[i-1][j];
                
            }
            // if the current weight can hold the new item of the row , then maximize between skiping it or picking it .
            else{
                T[i][j] = max(T[i-1][j] , (ele[i].second + T[i-1][j-ele[i].first]));
                
            }
        }
    }
    /* for(auto v:T){
        for(auto i:v)cout<<i<<' ';
        cout<<'\n';
    } */
    cout<<T[nEle][maxW]<<'\n';

    // getting the optimal set 
    int i = nEle , j = maxW ;
    while(T[i][j] != 0){
        if(T[i][j] != T[i-1][j]){
            cout<<ele[i].first<<' ';
            j -=  ele[i].first;
            i--;
        }
        else{
            i--;
        }
    }



    return 0;
}
/*
max  ele
34   5
34  5
178 12
30 1
13 7
34 8
87 6


7 4 
1 1
4 5
3 4
5 7
*/

