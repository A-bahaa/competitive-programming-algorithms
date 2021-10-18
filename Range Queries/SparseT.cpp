#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
 
const int N=1e5+5, M=1e3+5, MOD=1e9+7,OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
 
int n;
vector<int>arr;
vector<vector<int>>table;
 


// getting the log2() in o(1) .
int Log(int x){
    return 31-__builtin_clz(x);
} 
 
 
void buildTable(){
    table=vector<vector<int>>(n,vector<int>(Log(n)+1));
    // the min of ranges of length 1 = the same and only element in that range
    for(int i=0; i<n; i++)
        table[i][0]=arr[i];
    // for all possible types of ranges
    for(int j=1; (1<<j)<=n; j++)
        // for all possible starts to that type of range
        for(int i=0; i+(1<<j)-1<n; i++)
            // evry range of size l is a composite of two pre-calculated ranges of size l/2
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
}
 
 
int query(int l, int r){
   
   // j is the length of the longest range whose length is a power of 2 , that can be found in the query .
   int j=Log(r-l+1);
   return min(table[l][j],table[r-(1<<j)+1][j]);
    


    /* suppose we have this arr =  {5,-8,5,2,0,9,6,7,1} and the query q = min(1,7) ,
    the above implementation           *-----$-----* will get the length of the longest power-of-two ranges in the query length (that's because the table only holds the answer for the power-of-two ranges) then will return the answer in o(1) .*/


    /*the below implementation tackles things differently , since the lenght of the query -just like any other number- is a composite os powers of 2 .. in this case 7 is a composite of 1+2+4 and we can get the answer to these sub-ranges from the table in O(1) so we can loop through these sub-ranges to get the final answer but that would be in a log2(l) , since there're log2(l) sub-ranges*/

    
    // int len=r-l+1;
    // int ls=Log(len);
    // int st=l;
    // int mn=OO;
    // for(int j=0; j<=ls; j++){
    //     if((len>>j)&1){
    //         mn=min(mn,table[st][j]);
    //         st+=(1<<j);
    //     }
    // }
    // return mn;
 
}
 
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    
    // the size of the array
    cin>>n;
    arr=vector<int>(n);
    for(int &x : arr) cin>>x;
    buildTable();
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
 
    return 0;
}
