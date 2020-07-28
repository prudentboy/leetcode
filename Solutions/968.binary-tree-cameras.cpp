/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    int minCameraCover(TreeNode* root) {
        int ans(0);
        if (dfs(root, ans) == 0) { ++ans; }
        return ans;
    }
private:
    // 0-need cover, 1-covered, 2-camera
    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr) { return 1; }
        int l(dfs(root->left, ans)), r(dfs(root->right, ans));
        if (l == 0 || r == 0) {
            ++ans;
            return 2;
        }
        if (l == 2 || r == 2) { return 1; }
        return 0;
    }
};
// @lc code=end

