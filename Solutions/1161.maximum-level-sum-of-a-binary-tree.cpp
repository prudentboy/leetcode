/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        int ans(1);
        long long int mx(root->val), sum(0);
        int level(1), len(0);
        queue<TreeNode*> q;
        TreeNode* tmp(nullptr);
        q.push(root);
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
            if (sum > mx) {
                mx = sum;
                ans = level;
            }
            ++level;
        }
        return ans;
    }
};
// @lc code=end

