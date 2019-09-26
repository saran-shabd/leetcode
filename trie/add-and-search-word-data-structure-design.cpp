#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    bool is_last;
    unordered_map<char, TreeNode*> children;
    
    TreeNode() { is_last = false; }
};

class WordDictionary {
public:
    WordDictionary(): root(new TreeNode) {}
    
    void addWord(const string& word);
    bool search(const string& word);
    
private:
    TreeNode* root;
    
    bool search(const string& word, TreeNode* currnode, const int& index);
};

void WordDictionary::addWord(const string& word) {
    TreeNode* currnode = root;
    for (char item : word) {
        if (currnode->children.end() == currnode->children.find(item))
            currnode->children[item] = new TreeNode();
        currnode = currnode->children[item];
    }
    currnode->is_last = true;
}

bool WordDictionary::search(const string& word) {
    return search(word, root, 0);
}

bool WordDictionary::search(const string& word, TreeNode* currnode, const int& index) {
  
    if (index == word.size()) return currnode->is_last;
    
    if (currnode->children.end() != currnode->children.find(word[index])) {
    
        return search(word, currnode->children[word[index]], index + 1);
 
    } else if ('.' == word[index]) {
        
        for (pair<char, TreeNode*> curr_child : currnode->children) {
    
            bool curr_result = search(word, curr_child.second, index + 1);
            if (true == curr_result) return true;
        }
        
        return false;
    
    } else return false;
}
