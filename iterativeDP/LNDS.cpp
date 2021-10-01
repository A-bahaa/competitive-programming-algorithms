#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // how many numbers
    int n; cin>>n;
    // vector nums will hold the actual values , while vector ans will hold the answer to the sub-problems and hence the minimum answer is '1' (choosing only 1 element) , it's initialized with ones .
    vi nums(n) , ans(n,1);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    // starting at the second element we'll ask each element exactly 'i' questions . 
    for(int j = 1; j<n; j++){
        for(int i = 0; i<j; i++){
            //the first part of the question .. Can the nums[j] element extend the longest non decreasing subsequence that ends at the nums[i] element .
            if(nums[j]>=nums[i]){
                // if it can , the second part of the question is evaluated , what would be better appending the nums[j] element to the end of the longest non decreasing subsequence that ends at the nums[i] element so the new length of the subsequence would be 1(the element at nums[j])+ans[i] OR leaving the nums[j] element at its current non decreasing subsequence .. we choose the longer one . 
                ans[j] = max( ans[j] , 1 + ans[i] );

            }
        
        }
    }
    pair<int,int>maxi = {-1,0};
    // we loop through the ans array to get the maximum value and its position
    for(int i = 0; i<n; i++){
        if(ans[i]>maxi.first){
            maxi.first = ans[i];
            maxi.second = i;
        }
    }
    cout<<"the length of the longest non-decreasing subsequence is "<<maxi.first<<" and its elements ";
    for(int i = maxi.second; (i>=0 && maxi.first>0); i--){
        if(ans[i] == maxi.first){
            cout<<nums[i]<<' ';
            maxi.first-- ;
        }
    }

    return 0;
}