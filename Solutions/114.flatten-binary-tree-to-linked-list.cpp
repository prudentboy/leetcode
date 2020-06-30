/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr or isLeaf(root)) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* right = root->right;
        TreeNode* left = root->left;

        root->left = nullptr;
        root->right = nullptr;

        TreeNode* tmp(left);
        if (tmp != nullptr) root->right = tmp;
        else
        {
            root->right = right;
            return;
        }

        while (tmp->right != nullptr) tmp = tmp->right;

        tmp->right = right;
    }
private:
    const bool isLeaf(TreeNode* root)
    {
        if (root == nullptr) return false;
        return (root->left == nullptr) and (root->right == nullptr);
    }
};

