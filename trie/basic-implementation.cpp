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

int main() {
    
    Trie* trie = new Trie();

    cout << "enter words to insert in trie:\n";
    while (true) {
        string word; cin >> word;
        if ("exit" == word) break;
        trie->add_word(word);
    }

    cout << "\n";

    cout << "enter word to search: ";
    string search; cin >> search;
    cout << (trie->search_word(search) ? "word found" : "word not found") << "\n";

    cout << "enter prefix to search: ";
    string prefix; cin >> prefix;
    cout << (trie->search_prefix(prefix) ? "prefix found" : "prefix not found") << "\n";

    cout << "\n";

    cout << "enter word to delete: ";
    string delete_word; cin >> delete_word;
    trie->delete_word(delete_word);

    cout << "\n";

    cout << "enter word to search: ";
    search; cin >> search;
    cout << (trie->search_word(search) ? "word found" : "word not found") << "\n";

    cout << "enter prefix to search: ";
    prefix; cin >> prefix;
    cout << (trie->search_prefix(prefix) ? "prefix found" : "prefix not found") << "\n";

    delete trie;

    return 0;
}
