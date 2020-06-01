/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        // Recursive solution:
        if (root == nullptr) { return true; }
        return isValidLeftBST(root->left, root->val, LONG_MIN) && \
               isValidRightBST(root->right, root->val, LONG_MAX);

        // Traverse solution:
        vector<int> inArr;
        inorderTraverse(root, inArr);
        for (int i(1); i < inArr.size(); ++i) {
            if (inArr[i] <= inArr[i - 1]) { return false; }
        }
        return true;
    }
private:
    bool isValidLeftBST(TreeNode* root, int pVal, long long int minVal) {
        if (root == nullptr) { return true; }
        if (root->val >= pVal || root->val <= minVal) { return false; }
        return isValidLeftBST(root->left, root->val, minVal) && \
               isValidRightBST(root->right, root->val, pVal);
    }
    bool isValidRightBST(TreeNode* root, int pVal, long long int maxVal) {
        if (root == nullptr) { return true; }
        if (root->val <= pVal || root->val >= maxVal) { return false; }
        return isValidLeftBST(root->left, root->val, pVal) && \
               isValidRightBST(root->right, root->val, maxVal);
    }
    void inorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        inorderTraverse(root->left, ans);
        ans.push_back(root->val);
        inorderTraverse(root->right, ans);
    }
};
// @lc code=end

