/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) return node;
        TreeNode* tmp(root);
        while (true)
        {
            if (tmp->val > val)
            {
                if (tmp->left == nullptr)
                {
                    tmp->left = node;
                    break;
                }
                tmp = tmp->left;
            }
            else
            {
                if (tmp->right == nullptr)
                {
                    tmp->right = node;
                    break;
                }
                tmp = tmp->right;
            }
        }
        return root;
    }
};
// @lc code=end

