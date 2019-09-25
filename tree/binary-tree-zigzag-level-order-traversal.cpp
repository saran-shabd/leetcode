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
    vii zigzagLevelOrder(const TreeNode* root);
private:
    int get_height(const TreeNode* root);
    void level_order(const TreeNode* root, const int& index, const bool& direction, vi& arr);
};

vii Solution::zigzagLevelOrder(const TreeNode* root) {
    int height = get_height(root);
    bool direction = true;
    vii result;
    vi arr;
    
    for (int i = 0; i < height; ++i) {
        level_order(root, i, direction, arr);
        result.push_back(arr);
        arr.clear();
        direction = !direction;
    }
    
    return result;
}

int Solution::get_height(const TreeNode* root) {
    if (nullptr == root) return 0;
    int left_tree = get_height(root->left);
    int right_tree = get_height(root->right);
    return 1 + max(left_tree, right_tree);
}

void Solution::level_order(const TreeNode* root, const int& index, const bool& direction, vi& arr) {
    if (nullptr == root) return;
    if (0 == index) arr.push_back(root->val);
    else {
        if (true == direction) {
            level_order(root->left, index-1, direction, arr);
            level_order(root->right, index-1, direction, arr);
        } else {
            level_order(root->right, index-1, direction, arr);
            level_order(root->left, index-1, direction, arr);
        }
    }
}
