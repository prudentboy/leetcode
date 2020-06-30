/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
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
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr && head->child == nullptr) return head;
        Node* c(flatten(head->child));
        Node* n(flatten(head->next));
        if (c == nullptr) return head;
        head->next = c;
        head->child = nullptr;
        c->prev = head;
        if (n == nullptr) return head;
        Node* tmp(c);
        while (tmp->next != nullptr) tmp = tmp->next;
        tmp->next = n;
        n->prev = tmp;
        return head;
    }
};
// @lc code=end

