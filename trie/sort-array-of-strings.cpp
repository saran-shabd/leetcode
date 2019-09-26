#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool is_last;
    map<char, TrieNode*> children;
    TrieNode();
};

class Trie {
public:
    Trie();
    void add_word(const string& word);
    void print_all();

private:
    TrieNode* root;
    void preorder(TrieNode*& currnode, char curr_char, vector<char>& arr);
};

TrieNode::TrieNode() { is_last = false; }

Trie::Trie(): root(new TrieNode()) {}

void Trie::add_word(const string& word) {
    TrieNode* currnode = root;
    
    for (char item : word) {
        if (currnode->children.end() == currnode->children.find(item))
            currnode->children[item] = new TrieNode();
        currnode = currnode->children[item];
    }

    currnode->is_last = true;
}

void Trie::print_all() {

    vector<char> arr;
    preorder(root, '\0', arr);
}

void Trie::preorder(TrieNode*& currnode, char curr_char, vector<char>& arr) {
    if ('\0' != curr_char) arr.push_back(curr_char);

    if (currnode->is_last) {
        for (char item : arr) cout << item;
        cout << "\n";
    }

    for (pair<char, TrieNode*> curr_pair : currnode->children) {
        preorder(curr_pair.second, curr_pair.first, arr);
    }

    if ('\0' != curr_char) arr.pop_back();
}
