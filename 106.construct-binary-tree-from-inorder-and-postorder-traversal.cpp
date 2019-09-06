/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& inorder, size_t in_begin, size_t in_end, vector<int>& postorder, size_t post_begin, size_t post_end)
    {
        if (in_begin >= in_end or in_begin < 0 or in_end > inorder.size() or post_begin >= post_end or post_begin < 0 or post_end > postorder.size())
        {
            return nullptr;
        }

        int val(postorder[post_end - 1]);
        TreeNode* root = new TreeNode(val);
        size_t pos = find(inorder.begin() + in_begin, inorder.end() + in_end, val) - inorder.begin();
        root->left = buildTree(inorder, in_begin, pos, postorder, post_begin, post_begin + pos - in_begin);
        root->right = buildTree(inorder, pos + 1, in_end, postorder, post_begin + pos - in_begin, post_end - 1);

        return root;
    }
};

