/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> vec;
        pathSumHelper(root, vec, ans, sum);
        return ans;
    }

private:
    void pathSumHelper(TreeNode* root, vector<int>& vec, vector<vector<int>>& ans, int sum) {
        if (root == nullptr) return;

        vec.push_back(root->val);
        if (isLeafNode(root) and sum == root->val) ans.push_back(vec);

        pathSumHelper(root->left, vec, ans, sum - root->val);
        pathSumHelper(root->right, vec, ans, sum - root->val);

        vec.pop_back();
    }
private:
    bool isLeafNode(TreeNode* root)
    {
        if (root == nullptr) return false;
        return (root->left == nullptr) and (root->right == nullptr);
    }
};

