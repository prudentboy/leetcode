/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        int len(0);
        bool xb(false), yb(false);

        while (!q.empty())
        {
            len = q.size();
            while (len-- > 0)
            {
                tmp = q.front();
                q.pop();
                if (tmp->val == x) xb = true;
                if (tmp->val == y) yb = true;
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
                if (tmp->left != nullptr && tmp->right != nullptr)
                {
                    if ((tmp->left->val == x && tmp->right->val == y) || (tmp->left->val == y && tmp->right->val == x))
                        return false;
                }
            }
            if (xb && yb) return true;
            if (xb || yb) return false;
        }

        return false;
    }
};
// @lc code=end

