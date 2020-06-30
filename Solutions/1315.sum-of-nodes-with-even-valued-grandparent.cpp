/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
    int sumEvenGrandparent(TreeNode* root) {
        int ans(0);
        sumEvenGrandparent(root, false, false, ans);
        return ans;
    }
private:
    void sumEvenGrandparent(TreeNode* root, bool parent, bool grand, int& ans) {
        if (root == nullptr) { return; }
        if (grand) { ans += root->val; }
        if (root->left) sumEvenGrandparent(root->left, (root->val & 1) == 0, parent, ans);
        if (root->right) sumEvenGrandparent(root->right, (root->val & 1) == 0, parent, ans); 
    }
};
// @lc code=end

