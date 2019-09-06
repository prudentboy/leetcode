/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int res(INT_MIN);
        helper(root, res);
        return res;
    }
private:
    int helper(TreeNode* root, int& res)
    {
        if (root == nullptr) return 0;
        int left = max(helper(root->left, res), 0);
        int right = max(helper(root->right, res), 0);

        if (left + right + root->val > res) res = left + right + root->val;
        return max(left, right) + root->val;
    }
};

