/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans(nullptr);
        findTarget(original, cloned, target, ans);
        return ans;
    }
private:
    bool findTarget(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& ans) {
        if (original == nullptr) { return false; }
        if (original == target) {
            ans = cloned;
            return true;
        }
        return findTarget(original->left, cloned->left, target, ans) || findTarget(original->right, cloned->right, target, ans);
    }
};
// @lc code=end

