/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        getArr(root, arr);
        return arr[k - 1];
    }
private:
    void getArr(TreeNode* root, vector<int>& ans)
    {
        if (root == nullptr) return;
        getArr(root->left, ans);
        ans.push_back(root->val);
        getArr(root->right, ans);
    }
};

