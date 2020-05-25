/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // corner case
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        TreeNode* tmp = nullptr;
        vector<int> level;
        q.push(root);
        int len = 1;
        while (!q.empty()) {
            while (len-- > 0) {
                tmp = q.front();
                level.push_back(tmp->val);
                q.pop();
                if (tmp->left != nullptr) { q.push(tmp->left); }
                if (tmp->right != nullptr) { q.push(tmp->right); }
            }
            len = q.size();
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};
// @lc code=end

