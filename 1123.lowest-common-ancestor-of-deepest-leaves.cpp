/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) { return nullptr; }
        int left(depth(root->left)), right(depth(root->right));
        if (left == right) { return root; }
        if (left > right) { return lcaDeepestLeaves(root->left); }
        return lcaDeepestLeaves(root->right); 
    }
private:
    int depth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        if (depthUmp.count(root)) { return depthUmp[root]; }
        int ans = 1 + max(depth(root->left), depth(root->right));
        depthUmp[root] = ans;
        return ans;
    }
private:
    unordered_map<TreeNode *, int> depthUmp;
};
// @lc code=end

