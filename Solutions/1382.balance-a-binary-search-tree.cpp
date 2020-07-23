/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;

        function<void(TreeNode*)> inorderTraverse = [&](TreeNode* root) {
            if (root == nullptr) { return; }
            inorderTraverse(root->left);
            arr.push_back(root->val);
            inorderTraverse(root->right);
        };

        function<TreeNode*(int, int)> buildBalanceTree = [&](int left, int right) -> TreeNode* {
            if (left > right) { return nullptr; }
            int mid(left + ((right - left) >> 1));
            TreeNode* root(new TreeNode(arr[mid], buildBalanceTree(left, mid - 1), buildBalanceTree(mid + 1, right)));
            return root;
        };

        inorderTraverse(root);
        return buildBalanceTree(0, arr.size() - 1);
    }
};
// @lc code=end

