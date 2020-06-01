/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) { return ans; }

        queue<TreeNode*> q;
        vector<int> level;
        stack<vector<int>> st;
        TreeNode* tmp(nullptr);
        q.push(root);
        int len(1);

        while (!q.empty()) {
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if (tmp->left != nullptr) { q.push(tmp->left); }
                if (tmp->right != nullptr) { q.push(tmp->right); }
            }
            len = q.size();
            st.push(level);
            level.clear();
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
// @lc code=end

