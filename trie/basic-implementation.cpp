#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool is_last;
    unordered_map<char, TrieNode*> children;

    TrieNode() { is_last = false; }
};

class Trie {
public:
    Trie(): root(new TrieNode()) {}

    void add_word(const string& word);
    bool search_word(const string& word);
    bool search_prefix(const string& word);
    void delete_word(const string& word);

private:
    TrieNode* root;
};

void Trie::add_word(const string& word) {
   
    TrieNode* currnode = root;
   
    for (char item : word) {
   
        if (currnode->children.end() == currnode->children.find(item))
            currnode->children[item] = new TrieNode();
   
        currnode = currnode->children[item];
    }
   
    currnode->is_last = true;
}

bool Trie::search_word(const string& word) {
    
    TrieNode* currnode = root;

    for (char item : word) {

        if (currnode->children.end() == currnode->children.find(item))
            return false;
        
        currnode = currnode->children[item];
    }

    return currnode->is_last;
}

bool Trie::search_prefix(const string& word) {
    
    TrieNode* currnode = root;

    for (char item : word) {

        if (currnode->children.end() == currnode->children.find(item))
            return false;
        
        currnode = currnode->children[item];
    }

    return true;
}

void Trie::delete_word(const string& word) {
    
    stack<pair<char, TrieNode*>> nodes;
    TrieNode* currnode = root;

    for (char item : word) {

        if (currnode->children.end() == currnode->children.find(item))
            return;

        nodes.push(make_pair(item, currnode));
        currnode = currnode->children[item];
    }

    while (!nodes.empty()) {

        pair<char, TrieNode*> curr = nodes.top(); nodes.pop();

        if (curr.second->children.size() > 1 or curr.second->children.size() > 0) {
     
            curr.second->is_last = false;
            break;
     
        } else {
     
            curr.second->children.erase(curr.first);
        }
    }
}
