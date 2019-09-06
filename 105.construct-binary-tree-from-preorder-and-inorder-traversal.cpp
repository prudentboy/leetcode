/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& preorder, size_t pre_begin, size_t pre_end, vector<int>& inorder, size_t in_begin, size_t in_end)
    {
        if (pre_end <= pre_begin or pre_begin < 0 or pre_end > preorder.size() or in_end <= in_begin or in_begin < 0 or in_end > inorder.size())
        {
            return nullptr;
        }
        int val = preorder[pre_begin];
        TreeNode* root = new TreeNode(val);
        size_t pos = find(inorder.begin() + in_begin, inorder.begin() + in_end, val) - inorder.begin();
        root->left = buildTree(preorder, pre_begin + 1, pre_begin + pos - in_begin + 1, inorder, in_begin, pos);
        root->right = buildTree(preorder, pre_begin + pos - in_begin + 1, pre_end, inorder, pos + 1, in_end);

        return root;
    }
};

