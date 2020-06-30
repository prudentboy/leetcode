/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
    int distributeCoins(TreeNode* root) {
        int ans(0);
        deltaCoinNum(root, ans);
        return ans;
    }
private:
    int deltaCoinNum(TreeNode* root, int& ans) {
        if (root == nullptr) { return 0; }
        
        int left(deltaCoinNum(root->left, ans)), right(deltaCoinNum(root->right, ans));
        ans += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
};
// @lc code=end

