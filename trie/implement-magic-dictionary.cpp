#include <bits/stdc++.h>
using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

class TrieNode {
public:
    bool islast;
    map<char, TrieNode*> children;
    
    TrieNode() { islast = false; }
};

class MagicDictionary {
public:
    MagicDictionary(): root(new TrieNode()) {}
    
    void buildDict(const vector<string>& dict) {
        for (string word : dict) add_word(word);
    }
    
    bool search(const string& word) {
        unordered_map<pair<int, bool>, bool, hash_pair> storage;
        return search_word(root, word, 0, false, storage);
    }
    
private:
    TrieNode* root;
    
    void add_word(const string& word) {
        TrieNode* currnode = root;
  
        for (char item : word) {
            if (currnode->children.end() == currnode->children.find(item))
                currnode->children[item] = new TrieNode();

            currnode = currnode->children[item];
        }

        currnode->islast = true;
    }
    
    bool search_word(TrieNode* currnode, const string& word, const int index, const bool is_changed, unordered_map<pair<int, bool>, bool, hash_pair>& storage) {
        if (index == word.size())
            return currnode->islast && is_changed;
        
        if (storage.end() != storage.find(make_pair(index, is_changed)))
            return storage[make_pair(index, is_changed)];
        
        bool result = false;
        
        if (is_changed) {
            if (currnode->children.end() != currnode->children.find(word[index]))
                result = search_word(currnode->children[word[index]], word, index + 1, true, storage);
            else result = false;
        
        } else {
            for (pair<char, TrieNode*> child : currnode->children) {
                bool changed = search_word(child.second, word, index + 1, word[index] != child.first, storage);
                if (changed) result = true;
            }
            
            if (!result)
                if (currnode->children.end() != currnode->children.find(word[index]))
                    result = search_word(currnode->children[word[index]], word, index + 1, false, storage);
                else result = false;
        }
        
        storage[make_pair(index, is_changed)] = result;
        
        return result;
    }
};
