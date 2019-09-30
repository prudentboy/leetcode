/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return true;
        
        int val(root->val);
        return isUnivalTree(root, val);
    }
private:
    bool isUnivalTree(TreeNode* root, int val)
    {
        if (root == nullptr) return true;
        if (root->val != val) return false;
        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};

