/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans(root->val);
        int len(1);
        TreeNode* tmp(nullptr);

        while (!q.empty())
        {
            --len;
            tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);

            if (len == 0)
            {
                if (!q.empty()) ans = q.front()->val;
                len = q.size();
            }
        }

        return ans;
    }
};
// @lc code=end

