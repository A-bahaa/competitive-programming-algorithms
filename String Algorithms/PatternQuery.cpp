#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

// In this problem we have a string and q queries .. each one represents a pattern .. the question is how many patterns are represented in the string as subs.

// the main idea is to make a trie out of all the patterns and then starting from each char of the string we travers the trie trying to find a leaf . 

// the previously discussed limitation of the trie will affect the answers so pay attention


class Trie{
    private:
        // initializing the building unit of the trie
        struct node{
            // every node has a bool var to determine if it's leaf or not
            bool leaf;
            // every node can take up to 26 other nodes as children
            node* child[26];
        };
        
        // intializing the root node of the trie
        node* root;
        
        // creats and return new node
		node* create(){
            node* nd=new node();
            // at first this new created node has no children
            for(int i=0; i<26; i++) nd->child[i]=NULL;
            // since it's the last created node in its branch , it's a leaf
            nd->leaf=1;
            // return the new created node
            return nd;
        }
 
    public:
        Trie(){
            // constructing the trie by creating the root node
            root=create();
        }
        
        // add strings to the trie
        void add(string s){
            // intializing the nd pointer , first it points to the root node 
            node* nd=root;
            for(int i=0; i<s.length(); i++){
                // if the current pointed node "the current root" doesn't have the char to be inserted as one of its children , then make one and point to it as the next root 
                if(nd->child[s[i]-'a']==NULL){
                    // our root isn't a leaf anymore 
                    nd->leaf=0;
                    nd->child[s[i]-'a']=create();
                }
                // point to it as the next root 
                nd=nd->child[s[i]-'a'];
            }
        }

         
        bool find(string s){
            node* nd = root;
            for(int i = 0; i<s.size(); i++){
                // if the current character being processed in the string isn't available in the trie , then the matching attempt is over and we check if the last common node is a leaf or not . 
                if(nd->child[s[i]-'a'] == NULL){
                    return nd->leaf;
                }
                nd = nd->child[s[i]-'a'];
            }
            // if we looped over the whole string and we didn't find a mis-match to end the attempt
            // then we check if the last common node is a leaf or not .
            return nd->leaf;
        }


};
 


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    // constructing a Trie opject named "trie"
    Trie trie = Trie();
    string s , p;
    cin>>s;
    //number of queries
    int q; cin>>q;
    while(q--){
        cin>>p;
        trie.add(p);
    }
    for(int i =0; i<s.size(); i++){
        cout<<(int)trie.find(s.substr(i));
    }

    return 0;
}

