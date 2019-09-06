/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
/*
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
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        Node* tmp(root->next);
        while (tmp != nullptr)
        {
            if (tmp->left != nullptr)
            {
                tmp = tmp->left;
                break;
            }
            if (tmp->right != nullptr)
            {
                tmp = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        if (root->right != nullptr) root->right->next = tmp;
        if (root->left != nullptr) root->left->next = (root->right == nullptr) ? tmp : root->right;

        connect(root->right);
        connect(root->left);
        return root;
    }
};

