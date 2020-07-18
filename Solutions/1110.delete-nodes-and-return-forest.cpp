/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> ust(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        delNodes(root, true, ans, ust);
        return ans;
    }
private:
    TreeNode* delNodes(TreeNode* root, bool flag, vector<TreeNode*>& ans, const unordered_set<int>& dict) {
        if (root == nullptr) { return nullptr; }
        if (dict.count(root->val) > 0) {
            delNodes(root->left, true, ans, dict);
            delNodes(root->right, true, ans, dict);
            return nullptr;
        }
        if (flag) {
            ans.push_back(root);
            root->left = delNodes(root->left, false, ans, dict);
            root->right = delNodes(root->right, false, ans, dict);
            return root;
        }
        root->left = delNodes(root->left, false, ans, dict);
        root->right = delNodes(root->right, false, ans, dict);
        return root;
    }
};
// @lc code=end

