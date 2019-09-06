/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        int len(1);

        while (not q.empty())
        {
            tmp = q.front();
            q.pop();
            --len;
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);

            if (len == 0)
            {
                ans.push_back(tmp->val);
                len = q.size();
            }
        }

        return ans;
    }
};

