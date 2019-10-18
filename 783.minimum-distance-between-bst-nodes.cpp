/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        transBSTVec(root, v);

        int ans(v[1] - v[0]);
        for (int i(2); i < v.size(); ++i)
        {
            ans = min(ans, v[i] - v[i - 1]);
        }
        
        return ans;
    }
private:
    void transBSTVec(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr) return;
        if (root->left != nullptr) transBSTVec(root->left, v);
        v.push_back(root->val);
        if (root->right != nullptr) transBSTVec(root->right, v);
    }
};
// @lc code=end

