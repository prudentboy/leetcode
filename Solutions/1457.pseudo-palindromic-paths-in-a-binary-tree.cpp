/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    int pseudoPalindromicPaths (TreeNode* root) {
        int mark(0), ans(0);
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            mark ^= 1 << root->val;
            if (isLeaf(root) && (mark & mark - 1) == 0) { ++ans; }
            if (root->left != nullptr) { dfs(root->left); }
            if (root->right != nullptr) { dfs(root->right); }
            mark ^= 1 << root->val;
        };

        dfs(root);

        return ans;
    }
private:
    inline bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
// @lc code=end

