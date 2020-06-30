/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left != nullptr || root->right != nullptr) return root;
        if (root->val != 0) return root;
        return nullptr;
    }
};
// @lc code=end

