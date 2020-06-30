/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int maxAncestorDiff(TreeNode* root) {
        int ans(0);
        int mx(root->val), mn(root->val);
        if (root->left != nullptr) { maxAncestorDiff(root->left, mx, mn, ans); }
        if (root->right != nullptr) { maxAncestorDiff(root->right, mx, mn, ans); }
        return ans;
    }
private:
    void maxAncestorDiff(TreeNode* root, int mx, int mn, int& ans) {
        ans = max(ans, abs(root->val - mx));
        ans = max(ans, abs(root->val - mn));
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        if (root->left != nullptr) { maxAncestorDiff(root->left, mx, mn, ans); }
        if (root->right != nullptr) { maxAncestorDiff(root->right, mx, mn, ans); }
    }
};
// @lc code=end

