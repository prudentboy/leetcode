/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans(0);
        if (root == nullptr) return ans;
        if (root->val >= L && root->val <= R) ans += root->val;
        if (root->val < R) ans += rangeSumBST(root->right, L, R);
        if (root->val > L) ans += rangeSumBST(root->left, L, R);

        return ans;
    }
};

