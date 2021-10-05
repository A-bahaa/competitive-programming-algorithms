#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    
    // every cell(i,j) holds the answer of the following sub-problem "what is the longest palindrome subsequence starinng from the ith character up to the jth character ?"
    vector<vector<int>>T(s.size(),vector<int>(s.size(),0));
    //setting the main diagonal to 1 , since the length of LPS of only one character is that one character so 1 is the answer to this sub-problem .
    for(int i = 0; i<s.size(); i++){
        T[i][i] = 1;
    }
    
    for(int l = 1; l<=s.size()-1; l++){
        for(int i = 0; i<s.size()-l; i++){
            if(s[i]==s[i+l]){
                // if the two characters are the same that means they can contribute to a palindromic subsequence of length : 2(the two new chars + the length of the sub-problem that starts *^---* here and ends *---^* here)
                T[i][i+l]=2+T[i+1][i+l-1];
            }
            // if the two characters are not the same , then the answer to this sub-problem which of length l+1 would be the maximum between the two previous sub-problems of length l which can be found in the following two cells : T[i][i+l-1] , T[i+1][i+l]
            else{
                T[i][i+l] = max(T[i][i+l-1] , T[i+1][i+l]);
            }

        }
    }

    // printing the table
    for(auto v : T){
        for(auto i : v)cout<<i<<' ';
        cout<<'\n';
    }
    //the answer of the original problem 
    cout<<T[0][s.size()-1]<<'\n';

    // to get that palindrome
    // to hold the up-front half of characters
    queue<char>q;
    // to hold the later half
    stack<char>sk;
    int i  = 0 , j = s.size()-1;
    while(T[i][j] && i<=s.size()-1 && j>=0){

        //the palindrome will be updated only when we move diagonally
        if(T[i][j-1]==T[i+1][j] && T[i][j]==T[i+1][j-1]+2){
            q.push(s[i]);
            sk.push(s[j]);
            i++;
            j--;
        }
        // if we reached the middle char
        else if(T[i+1][j-1]==0){
            q.push(s[i]);
            i++;
            j--;
        }
        // else we move through the table
        // moving left
        else if(T[i][j]==T[i][j-1])j--;
        // moving down
        else {
            i++;
        }


    }
    // printing the subsequence
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    while(!sk.empty()){
        cout<<sk.top();
        sk.pop();
    }
   
  

    return 0;
}