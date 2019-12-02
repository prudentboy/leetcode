/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 1});
        pair<TreeNode*, int> tmp;
        int ans(1), len(0), start(0), end(0), i(0);
        while (!q.empty())
        {
            start = -1;
            len = q.size();
            if (len == 1) q.front().second = 1;
            while (len-- > 0)
            {
                tmp = q.front();
                q.pop();
                if (start == -1) start = tmp.second;
                end = tmp.second;
                if (tmp.first->left != nullptr) q.push({tmp.first->left, 2 * tmp.second});
                if (tmp.first->right != nullptr) q.push({tmp.first->right, 2 * tmp.second + 1});
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
// @lc code=end

