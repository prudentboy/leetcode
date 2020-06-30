/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        int l(0), r(0);
        return rob(root, l, r);
    }
private:
    int rob(TreeNode* root, int& l, int& r)
    {
        if (root == nullptr) return 0;
        int ll(0), lr(0), rl(0), rr(0);
        l = rob(root->left, ll, lr);
        r = rob(root->right, rl, rr);
        //cout << root->val << ' ' << l << ' ' << r << endl;
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};
// @lc code=end

