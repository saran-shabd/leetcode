#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head);
};

Node* Solution::flatten(Node* head) {
    Node* curr = head;
    
    while (nullptr != curr) {
        if (nullptr != curr->child) {
            Node* temp = curr->next;
            curr->next = curr->child;
            curr->child = nullptr;
            curr->next->prev = curr;
            
            Node* iterator = curr;
            while (nullptr != iterator->next) iterator = iterator->next;
            iterator->next = temp;
            if (nullptr != iterator->next)
                iterator->next->prev = iterator;
        }
        
        curr = curr->next;
    }
    
    return head;
}
