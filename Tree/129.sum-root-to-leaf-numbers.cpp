/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int ans(0);
        if (root == nullptr) { return ans; }
        sumNumbers(root, 0, ans);
        return ans;
    }
private:
    void sumNumbers(TreeNode* root, int now, int& ans) {
        now *= 10;
        now += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ans += now;
        }
        if (root->left != nullptr) { sumNumbers(root->left, now, ans); }
        if (root->right != nullptr) { sumNumbers(root->right, now, ans); }
    }
};
// @lc code=end

