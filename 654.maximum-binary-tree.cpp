/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* constructMaximumBinaryTree(const vector<int>& nums, int beg, int end)
    {
        if (beg > end) return nullptr;
        int index = findMaxIndex(nums, beg, end);
        TreeNode* root = new TreeNode(nums[index]);
        root->left = constructMaximumBinaryTree(nums, beg, index - 1);
        root->right = constructMaximumBinaryTree(nums, index + 1, end);
        return root;
    }
    int findMaxIndex(const vector<int>& nums, int beg, int end)
    {
        int ans = beg;
        for (int i = beg + 1; i <= end; ++i)
            if (nums[i] > nums[ans]) ans = i;
        return ans;
    }
};
// @lc code=end

