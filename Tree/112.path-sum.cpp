/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) { return false; }
        if (root->left == nullptr && root->right == nullptr) { return sum == root->val; }
        if (root->left == nullptr) { return hasPathSum(root->right, sum - root->val); }
        if (root->right == nullptr) { return hasPathSum(root->left, sum - root->val); }
        return hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val); 
    }
};
// @lc code=end

