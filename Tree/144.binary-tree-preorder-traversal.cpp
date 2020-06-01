/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //preorderTraversalRecur(root, ans);
        preorderTraversalIter(root, ans);
        return ans;
    }
private:
    void preorderTraversalRecur(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }

        ans.push_back(root->val);
        preorderTraversalRecur(root->left, ans);
        preorderTraversalRecur(root->right, ans);
    }
    void preorderTraversalIter(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }

        set<TreeNode*> st;
        TreeNode* tmp(nullptr);
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            tmp = stk.top();
            //cout << tmp->val << endl;
            if (st.count(tmp) == 0) {
                ans.push_back(tmp->val);
                st.insert(tmp);
            } else {
                stk.pop();
                if (tmp->right != nullptr) { stk.push(tmp->right); }
            }
            if (tmp->left != nullptr) { stk.push(tmp->left); }
        }
    }
};
// @lc code=end

