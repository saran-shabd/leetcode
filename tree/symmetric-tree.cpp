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
    bool isSymmetric(const TreeNode* root);
private:
    bool isSymmetric(const TreeNode* root1, const TreeNode* root2);
};

bool Solution::isSymmetric(const TreeNode* root) {
    return isSymmetric(root, root);
}

bool Solution::isSymmetric(const TreeNode* root1, const TreeNode* root2) {
    if (nullptr == root1 and nullptr == root2) return true;
    
    if (nullptr != root1 and nullptr != root2 and root1->val == root2->val)
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    
    return false;
}
