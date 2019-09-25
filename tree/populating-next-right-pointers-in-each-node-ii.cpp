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
    int get_height(const Node* root);
    void level_order(Node* root, const int& index, vector<Node*>& nodes);
};

Node* Solution::connect(Node* root) {
    int height = get_height(root);
    vector<Node*> nodes;
    
    for (int i = 0; i < height; ++i) {
        level_order(root, i, nodes);
    
        for (int i = 0; i < nodes.size() - 1; ++i)
            nodes[i]->next = nodes[i+1];
        nodes[nodes.size() - 1]->next = nullptr;
        
        nodes.clear();
    }
    
    return root;
}

void Solution::level_order(Node* root, const int& index, vector<Node*>& nodes) {
    if (nullptr == root) return;
    if (0 == index) nodes.push_back(root);
    
    level_order(root->left, index-1, nodes);
    level_order(root->right, index-1, nodes);
}

int Solution::get_height(const Node* root) {
    if (nullptr == root) return 0;
        
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
        
    return 1 + max(left_height, right_height);
}
