/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int ans(1);
        goodNodes(root->left, root->val, ans);
        goodNodes(root->right, root->val, ans);
        return ans;
    }
private:
    void goodNodes(TreeNode* root, int val, int& ans) {
        if (root == nullptr) { return; }
        if (val <= root->val) { ++ans; }
        val = max(val, root->val);
        goodNodes(root->left, val, ans);
        goodNodes(root->right, val, ans);
    }
};
// @lc code=end

