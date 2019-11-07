/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) 
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode* tmp(root->left);
        while (tmp->right != nullptr) tmp = tmp->right;
        swap(root->val, tmp->val);
        root->left = deleteNode(root->left, key);
        return root;
    }
};
// @lc code=end

