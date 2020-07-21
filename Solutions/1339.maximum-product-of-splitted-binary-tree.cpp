/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    int maxProduct(TreeNode* root) {
        unordered_set<int> ust;
        int all(getSums(root, ust));
        long long int ans(0);
        for (int n : ust) { ans = max(ans, (long long int)n * (all - n)); }
        return ans % 1000000007;
    }
private:
    int getSums(TreeNode* root, unordered_set<int>& sums) {
        if (root == nullptr) { return 0; }
        int sum(root->val);
        sum += getSums(root->left, sums);
        sum += getSums(root->right, sums);
        sums.insert(sum);
        return sum;
    }
};
// @lc code=end

