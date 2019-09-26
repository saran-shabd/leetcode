#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool is_last;
    vector<TrieNode*> children;
    
    TrieNode() {
        is_last = false;
        for (int i = 0; i < 26; ++i)
            children.push_back(nullptr);
    }
};

class Trie {
public:
    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* currnode = root;
        
        for (char item : word) {
            int index = item - 'a';
        
            if (nullptr == currnode->children[index])
                currnode->children[index] = new TrieNode();
            
            currnode = currnode->children[index];
        }
        
        currnode->is_last = true;
    }
    
    bool search(string word) {
        TrieNode* currnode = root;
        
        for (char item : word) {
            int index = item - 'a';
            if (nullptr == currnode->children[index]) return false;
            currnode = currnode->children[index];
        }
        
        return currnode->is_last;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currnode = root;
        
        for (char item : prefix) {
            int index = item - 'a';
            if (nullptr == currnode->children[index]) return false;
            currnode = currnode->children[index];
        }
        
        return true;
    }

private:
    TrieNode* root;
};
