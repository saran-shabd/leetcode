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
    bool hasPathSum(const TreeNode* root, const int& sum);
private:
    bool hashPathSum(const TreeNode* root, int currsum, const int& sum);
};

bool Solution::hasPathSum(const TreeNode* root, const int& sum) {
    if (nullptr == root) return false;
    return hashPathSum(root, 0, sum);
}

bool Solution::hashPathSum(const TreeNode* root, int currsum, const int& sum) {
    if (nullptr == root) return false;
    
    currsum += root->val;
    
    if (currsum == sum and nullptr == root->left and nullptr == root->right) return true;
    
    bool left_result = hashPathSum(root->left, currsum, sum);
    if (true == left_result) return true;
    
    return hashPathSum(root->right, currsum, sum);
}
