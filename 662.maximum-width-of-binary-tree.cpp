/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans(1);
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp(nullptr);
        int level_max(1);
        int sure(0), 

        while (!q.empty())
        {
            tmp = 
        }
    }
};
// @lc code=end

