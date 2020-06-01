/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr) { return ans; }
        pathSum(root, sum, {}, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int> now, vector<vector<int>>& ans) {
        now.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) { ans.push_back(now); }
        }
        if (root->left != nullptr) { pathSum(root->left, sum - root->val, now, ans); }
        if (root->right != nullptr) { pathSum(root->right, sum - root->val, now, ans); }
    }
};
// @lc code=end

