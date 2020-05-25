/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inorderTraversalRecur(root, ans);
        inorderTraversalIter(root, ans);
        return ans;
    }
private:
    void inorderTraversalRecur(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        inorderTraversalRecur(root->left, ans);
        ans.push_back(root->val);
        inorderTraversalRecur(root->right, ans);
    }
    void inorderTraversalIter(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        stack<TreeNode*> stk;
        set<TreeNode*> st;
        stk.push(root);
        TreeNode* tmp = nullptr;
        while (!stk.empty()) {
            tmp = stk.top();
            if (tmp->left == nullptr || st.count(tmp->left) > 0) {
                ans.push_back(tmp->val);
                st.insert(tmp);
                stk.pop();
                if (tmp->right != nullptr) { stk.push(tmp->right); }
            } else {
                stk.push(tmp->left);
            }
        }
    }
};
// @lc code=end

