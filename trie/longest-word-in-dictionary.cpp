#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool islast;
    map<char, TrieNode*> children;
    
    TrieNode();
};

TrieNode::TrieNode() { islast = false; }

class Solution {
public:
    string longestWord(const vector<string>& words);
private:
    TrieNode* root;
    
    void add_word(const string& word);
    bool search_word(const string& word);
    void get_longest_string(TrieNode* currnode, string curr_str, string& result);
};

string Solution::longestWord(const vector<string>& words) {
    root = new TrieNode();
    for (string item : words) add_word(item);
    vector<char> arr;
    string result = "";
    
    get_longest_string(root, "", result);
    return result;
}

void Solution::add_word(const string& word) {
    TrieNode* currnode = root;
  
    for (char item : word) {
        if (currnode->children.end() == currnode->children.find(item))
            currnode->children[item] = new TrieNode();
    
        currnode = currnode->children[item];
    }
    
    currnode->islast = true;
}

bool Solution::search_word(const string& word) {
    TrieNode* currnode = root;
    
    for (char item : word) {
        if (currnode->children.end() == currnode->children.find(item))
            return false;
      
        currnode = currnode->children[item];
    }
 
    return currnode->islast;
}

void Solution::get_longest_string(TrieNode* currnode, string curr_str, string& result) {   
    
    if (currnode->islast) {
        if (curr_str.size() > result.size())
            result = curr_str;
        else if (curr_str.size() == result.size())
            result = min(result, curr_str);
    }
    
    for (pair<char, TrieNode*> curr : currnode->children) {
        curr_str += curr.first;
        
        bool search_result = search_word(curr_str);
        if (search_result)
            get_longest_string(curr.second, curr_str, result);
        
        curr_str = curr_str.substr(0, curr_str.size() - 1);
    }
}
