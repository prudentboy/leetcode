/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};

        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode(1));
        
        int i(0), j(0), x(0), y(0);
        for (i = 2; i <= n; ++i) {
            for (j = 1; j <= i; ++j) {
                for (x = 0; x < dp[j - 1].size(); ++x) {
                    TreeNode* left = copyTreeAndAddN(dp[j - 1][x], 0);
                    for (y = 0; y < dp[i - j].size(); ++y) {
                        TreeNode* right = copyTreeAndAddN(dp[i - j][y], j);
                        dp[i].push_back(new TreeNode(j, left, right));
                    }
                }
            }
        }
        
        return dp[n];
    }
private:
    TreeNode* copyTreeAndAddN(TreeNode* root, int n) {
        if (root == nullptr) { return nullptr; }
        
        TreeNode* ans(new TreeNode(root->val + n));
        ans->left = copyTreeAndAddN(root->left, n);
        ans->right = copyTreeAndAddN(root->right, n);
        
        return ans;
    }
};
// @lc code=end

