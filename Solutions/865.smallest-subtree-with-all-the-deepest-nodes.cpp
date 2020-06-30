/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> depth;
        return subtreeWithAllDeepest(root, depth);
    }
private:
    TreeNode* subtreeWithAllDeepest(TreeNode* root, unordered_map<TreeNode*, int>& depth) {
        if (root == nullptr) { return nullptr; }
        int dep_left(getDepth(root->left, depth));
        int dep_right(getDepth(root->right, depth));
        if (dep_left == dep_right) { return root; }
        if (dep_left > dep_right) { return subtreeWithAllDeepest(root->left, depth); }
        return subtreeWithAllDeepest(root->right, depth);
    }
    int getDepth(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (m.count(root) > 0) return m[root];
        if (root == nullptr) {
            m[root] = 0;
            return 0;
        }
        int dep = max(getDepth(root->left, m), getDepth(root->right, m)) + 1;
        m[root] = dep;
        return dep;
    }
};
// @lc code=end

