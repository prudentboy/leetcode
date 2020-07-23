/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int longestZigZag(TreeNode* root) {
        int ans(0);
        TreeNode* head(new TreeNode(0, root, nullptr));
        longestZigZag(head->left, true, -1, ans);
        delete head;
        return ans;
    }
private:
    void longestZigZag(TreeNode* root, bool isLeft, int len, int& ans) {
        if (root == nullptr) { return; }
        ans = max(ans, ++len);
        //cout << isLeft << ' ' << len << ' ' << ans << endl;
        longestZigZag(root->left, true, isLeft ? 0 : len, ans);
        longestZigZag(root->right, false, isLeft ? len : 0, ans);
    }
};
// @lc code=end

