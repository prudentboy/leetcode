/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* bstFromPreorder(const vector<int>& preorder, int left, int right) {
        //cout << left << ' ' << right << endl;
        if (left < 0 || right >= preorder.size() || left > right) { return nullptr; }
        if (left == right) { return new TreeNode(preorder[left]); }
        TreeNode* root(new TreeNode(preorder[left]));
        int i(0);
        for (i = left + 1; i <= right; ++i) {
            if (preorder[i] > preorder[left]) { break; }
        }
        root->left = bstFromPreorder(preorder, left + 1, i - 1);
        root->right = bstFromPreorder(preorder, i, right);
        return root;
    }
};
// @lc code=end

