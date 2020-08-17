/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int maxSumBST(TreeNode* root) {
        int mn(0), mx(0), sum(0), ans(0);
        helper(root, mn, mx, sum, ans);
        return ans;
    }
private:
    bool helper(TreeNode* root, int& mn, int& mx, int& sum, int& ans) {
        if (root == nullptr) {
            sum = 0;
            return true;
        }
        sum = mn = mx = root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ans = max(ans, sum);
            return true;
        }
        int child_mn(INT_MAX), child_mx(INT_MIN), child_sum(0);
        bool ret(true);
        if (root->left != nullptr) {
            if (!helper(root->left, child_mn, child_mx, child_sum, ans) || root->val <= child_mx) { ret = false; }
            mx = max(mx, child_mx);
            mn = min(mn, child_mn);
            sum += child_sum;
        }
        if (root->right != nullptr) {
            if (!helper(root->right, child_mn, child_mx, child_sum, ans) || root->val >= child_mn) { ret = false; }
            mx = max(mx, child_mx);
            mn = min(mn, child_mn);
            sum += child_sum;
        }
        if (ret) { ans = max(ans, sum); }
        //cout << root->val << ' ' << ans << endl;
        return ret;
    }
};
// @lc code=end

