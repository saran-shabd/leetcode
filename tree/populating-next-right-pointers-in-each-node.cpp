#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root);
private:
    Node* helper(Node* root, Node* parent);
};

Node* Solution::connect(Node* root) {
    return helper(root, nullptr);
}

Node* Solution::helper(Node* root, Node* parent) {
    if (nullptr == root) return nullptr;
    
    if (nullptr == parent) root->next = nullptr;
    else if (root == parent->left) root->next = parent->right;
    else if (nullptr == parent->next) root->next = nullptr;
    else root->next = parent->next->left;
    
    root->left = helper(root->left, root);
    root->right = helper(root->right, root);
    
    return root;
}
