/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
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
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {{to_string(root->val)}};
        
        int h(getHeight(root));
        int w((1 << h) - 1);

        vector<vector<string>> ans(h, vector<string>(w, ""));
        helper(root, 0, w - 1, 0, h, ans);
        return ans;
    }
private:
    int getHeight(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    void helper(TreeNode* root, int beg, int end, int curH, const int h, vector<vector<string>>& ans)
    {
        if (root == nullptr || curH == h) return;
        ans[curH][(beg + end) >> 1].assign(to_string(root->val));
        helper(root->left, beg, (beg + end) >> 1, curH + 1, h, ans);
        helper(root->right, ((beg + end) >> 1) + 1, end, curH + 1, h, ans);
    }
};
// @lc code=end

