/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == nullptr) { return nullptr; }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val < limit ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if (root->left == nullptr && root->right == nullptr) { return nullptr; }
        return root;
    }
};
// @lc code=end

