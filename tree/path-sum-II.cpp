#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    vii pathSum(const TreeNode* root, const int& sum);
private:
    void pathSum(const TreeNode* root, int currsum, const int& sum, vi& arr, vii& result);
};

vii Solution::pathSum(const TreeNode* root, const int& sum) {
    vii result;
    vi arr;
    pathSum(root, 0, sum, arr, result);
    return result;
}

void Solution::pathSum(const TreeNode* root, int currsum, const int& sum, vi& arr, vii& result) {
    if (nullptr == root) return;
    
    currsum += root->val;
    arr.push_back(root->val);
    
    if (currsum == sum and nullptr == root->left and nullptr == root->right) {
        result.push_back(arr);
    } else {
        pathSum(root->left, currsum, sum, arr, result);
        pathSum(root->right, currsum, sum, arr, result);
    }
    
    arr.pop_back();
}
