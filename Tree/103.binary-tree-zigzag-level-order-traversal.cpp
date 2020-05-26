/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) { return ans; }
        
        queue<TreeNode*> q;
        TreeNode* tmp(nullptr);
        vector<int> level;
        q.push(root);
        int len(1);
        bool zig = false;

        while (!q.empty()) {
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if (tmp->left != nullptr) { q.push(tmp->left); }
                if (tmp->right != nullptr) { q.push(tmp->right); }
            }
            len = q.size();
            if (zig) { reverse(level.begin(), level.end()); }
            ans.push_back(level);
            level.clear();
            zig = !zig;
        }
        return ans;
    }
};
// @lc code=end

