/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left(lowestCommonAncestor(root->left, p, q));
        if (left != nullptr && left != p && left != q) return left;
        TreeNode* right(lowestCommonAncestor(root->right, p, q));
        if (right != nullptr && right != p && right != q) return right;
        if (left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;
    }
};

