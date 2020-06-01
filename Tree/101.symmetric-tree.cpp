/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) { return true; }
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) { return true; }
        if (root1 == nullptr || root2 == nullptr) { return false; }
        if (root1->val != root2->val) { return false; }
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};
// @lc code=end

