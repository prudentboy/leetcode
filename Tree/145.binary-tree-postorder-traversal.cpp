/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //postorderTraversalRecur(root, ans);
        postorderTraversalIter(root, ans);
        return ans;
    }
private:
    void postorderTraversalRecur(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }

        postorderTraversalRecur(root->left, ans);
        postorderTraversalRecur(root->right, ans);
        ans.push_back(root->val);
    }
    void postorderTraversalIter(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }

        set<TreeNode*> st;
        stack<TreeNode*> stk;
        TreeNode* tmp(nullptr);
        stk.push(root);

        while (!stk.empty()) {
            tmp = stk.top();
            if (tmp->left != nullptr && st.count(tmp->left) == 0) {
                stk.push(tmp->left);
            } else if (tmp->right != nullptr && st.count(tmp->right) == 0) {
                stk.push(tmp->right);
            } else {
                ans.push_back(tmp->val);
                st.insert(tmp);
                stk.pop();
            }
        }
    }
};
// @lc code=end

