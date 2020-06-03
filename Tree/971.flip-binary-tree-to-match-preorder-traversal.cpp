/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans, no_ans({-1});
        bool flag = flipMatchVoyage(root, voyage, 0, voyage.size() - 1, ans);
        return flag ? ans : no_ans;
    }
private:
    bool flipMatchVoyage(TreeNode* root, const vector<int>& voyage, int beg, int end, vector<int>& ans) {
        if (beg > end) { return true; }
        if (root == nullptr) { return false; }
        if (root->val != voyage[beg]) { return false; }
        if (root->left == nullptr && root->right == nullptr) { return beg == end; }
        if (root->left == nullptr) { return flipMatchVoyage(root->right, voyage, beg + 1, end, ans); }
        if (root->right == nullptr) { return flipMatchVoyage(root->left, voyage, beg + 1, end, ans); }
        if (beg + 1 >= voyage.size()) { return false; }
        int i(0);
        if (root->left->val == voyage[beg + 1]) {
            for (i = beg + 2; i <= end; ++i) {
                if (voyage[i] == root->right->val) { break; }
            }
            if (i > end) { return false; }
            return flipMatchVoyage(root->left, voyage, beg + 1, i - 1, ans) && \
                   flipMatchVoyage(root->right, voyage, i, end, ans);
        } else if (root->right->val == voyage[beg + 1]) {
            ans.push_back(root->val);
            for (i = beg + 2; i <= end; ++i) {
                if (voyage[i] == root->left->val) { break; }
            }
            if (i > end) { return false; }
            return flipMatchVoyage(root->right, voyage, beg + 1, i - 1, ans) && \
                   flipMatchVoyage(root->left, voyage, i, end, ans);
        } else {
            return false;
        }
    }
};
// @lc code=end

