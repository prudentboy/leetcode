/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) { return 0; }
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp(nullptr);
        int len(0), sum(0);
        while (!q.empty()) {
            len = q.size();
            sum = 0;
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                sum += tmp->val;
                if (tmp->left != nullptr) { q.push(tmp->left); }
                if (tmp->right != nullptr) { q.push(tmp->right); }
            }
        }
        return sum;
    }
};
// @lc code=end

