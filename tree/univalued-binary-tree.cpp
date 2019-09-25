#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (nullptr == root) return true;
        return check(root, root->val);
    }
    
    bool check(TreeNode* root, const int& value) {
        if (nullptr == root) return true;
        
        if (value != root->val) return false;
        
        bool left_result = check(root->left, value);
        bool right_result = check(root->right, value);
    
        return left_result && right_result;
    }
};
