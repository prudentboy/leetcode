/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum(0);
        turnBstToGst(root, sum);
        return root;
    }
private:
    void turnBstToGst(TreeNode* root, int& sum) {
        if (root == nullptr) { return; }
        turnBstToGst(root->right, sum);
        sum += root->val;
        root->val = sum;
        turnBstToGst(root->left, sum);
    }
};
// @lc code=end

