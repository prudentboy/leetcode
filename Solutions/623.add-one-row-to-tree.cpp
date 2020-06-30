/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1)
        {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        --d;
        if (d == 1)
        {
            TreeNode* l = new TreeNode(v);
            l->left = root->left;
            root->left = l;
            TreeNode* r = new TreeNode(v);
            r->right = root->right;
            root->right = r;
            return root;
        }
        --d;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp(nullptr);
        int len(1);
        while (!q.empty())
        {
            if (d <= 0) break;
            --len;
            tmp = q.front();
            //cout << d << ' ' << len << ' ' << tmp->val << endl;
            q.pop();
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);
            if (len == 0)
            {
                len = q.size();
                --d;
            }
        }
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            TreeNode* l = new TreeNode(v);
            l->left = tmp->left;
            tmp->left = l;
            TreeNode* r = new TreeNode(v);
            r->right = tmp->right;
            tmp->right = r;
        }
        return root;
    }
};
// @lc code=end

