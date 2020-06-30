/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root)
    {
        return sumNumbers(root, 0);
    }
private:
    int sumNumbers(TreeNode* root, int sum)
    {
        if (isEmpty(root)) return 0;

        sum = sum * 10 + root->val;

        if (isLeaf(root)) return sum;

        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
    inline bool isEmpty(TreeNode* root)
    {
        return root == nullptr;
    }
    inline bool isLeaf(TreeNode* root)
    {
        return (not isEmpty(root)) and (isEmpty(root->left)) and (isEmpty(root->right));
    }
};

