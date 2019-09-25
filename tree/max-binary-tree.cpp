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

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(const vi& arr);
private:
    int get_max_index(const vi& arr, const int& start, const int& end);
    TreeNode* generate_tree(const vi& arr, const int& start, const int& end);
};

TreeNode* Solution::constructMaximumBinaryTree(const vi& arr) {
    return generate_tree(arr, 0, arr.size() - 1);
}

TreeNode* Solution::generate_tree(const vi& arr, const int& start, const int& end) {
    if (start > end) return nullptr;
    
    int max_node = get_max_index(arr, start, end);
    TreeNode* rootnode = new TreeNode(arr[max_node]);
    rootnode->left = generate_tree(arr, start, max_node - 1);
    rootnode->right = generate_tree(arr, max_node + 1, end);
    
    return rootnode;
}

int Solution::get_max_index(const vi& arr, const int& start, const int& end) {
    int result_index = start;
    for (int i = start; i <= end; ++i)
        if (arr[i] > arr[result_index]) result_index = i; 
    return result_index;
}
