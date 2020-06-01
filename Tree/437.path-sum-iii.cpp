/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) { return 0; }
        int ans(0);
        pathSum(root, sum, {}, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int> now, int& ans) {
        now.push_back(root->val);
        
        int tmp = 0;
        for (int i(now.size() - 1); i >= 0; --i) {
            tmp += now[i];
            if (tmp == sum) { ++ans; }
        }

        if (root->left != nullptr) { pathSum(root->left, sum, now, ans); }
        if (root->right != nullptr) { pathSum(root->right, sum, now, ans); }
    }
};
// @lc code=end

