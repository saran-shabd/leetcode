#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(const Node* root) {
        return get_height(root);
    }
    
    int get_height(const Node* root) {
        if (nullptr == root) return 0;
        
        int result = 0;
        for (int i = 0; i < root->children.size(); ++i)
            result = max(result, get_height(root->children[i]));
        
        return 1 + result;
    }
};
