/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {};

        vector<TreeNode*> ans;
        unordered_map<string, int> s;
        helper(root->left, s, ans);
        helper(root->right, s, ans);
        return ans;
    }
private:
    string helper(TreeNode* root, unordered_map<string, int>& s, vector<TreeNode*>& ans)
    {
        if (root == nullptr) return "#";
        string ret(to_string(root->val));
        ret += 'L';
        ret.append(helper(root->left, s, ans));
        ret += 'R';
        ret.append(helper(root->right, s, ans));
        if (s[ret] == 1) ans.push_back(root);
        ++s[ret];
        return ret;
    }
};
// @lc code=end

