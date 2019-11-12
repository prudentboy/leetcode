/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int len(1), max(INT_MIN);
        TreeNode* tmp(nullptr);

        while (!q.empty())
        {
            --len;
            tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);
            if (tmp->val > max) max = tmp->val;
            if (len == 0)
            {
                ans.push_back(max);
                max = INT_MIN;
                len = q.size();
            }
        }

        return ans;
    }
};
// @lc code=end

