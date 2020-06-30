/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
private:
    TreeNode* constructFromPrePost(const vector<int>& pre, int preL, int preR, const vector<int>& post, int postL, int postR) {
        if (preL > preR || postL > postR) return nullptr;
        TreeNode* root = new TreeNode(pre[preL]);
        if (preL == preR) return root;
        int i(0);
        for (i = postL; i < postR; ++i) {
            if (post[i] == pre[preL + 1]) break;
        }
        root->left = constructFromPrePost(pre, preL + 1, preL + i - postL + 1, post, postL, i);
        root->right = constructFromPrePost(pre, preL + i - postL + 2, preR, post, i + 1, postR - 1);
        return root;
    }
};
// @lc code=end

