#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pb push_back
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9+7 , OO=0x3f3f3f3f; 

// In this problem , we have n number of strings and q number of queries each consists of a string that've te be determined if present in our previously entered collection .

// the idea is to make a trie out of the collection and then for each query we traverse the trie to see if we can get the string-of-the-query .

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
            for(int i =0; i<s.size(); i++){
                // in case of a mis-match , we know for sure that this string isn't present in our trie "collection"
                if(nd->child[s[i]-'a']==NULL){
                    return 0;
                }
                nd = nd->child[s[i]-'a'];
            }
            // after finding the whole string present in the trie we return true if and only if the last common node is a leaf .
            return nd->leaf;

        }

        

};
 


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    // constructing a Trie opject named "trie"
    Trie trie = Trie();
    // size of the collection
    int n; cin>>n;
    string s;
    while(n--){
        cin>>s;
        trie.add(s);
    }
    int q; cin>>q;
    string p;
    while (q--)
    {
        cin>>p;
        cout<<(int)trie.find(p)<<'\n';
    }
    
    return 0; 
}





  