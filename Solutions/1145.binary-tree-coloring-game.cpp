/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int winCnt((n + 1) >> 1);
        TreeNode* first(findNode(root, x));
        if (first == nullptr) { return true; }
        int left(cntNodes(first->left)), right(cntNodes(first->right));
        //cout << left << ' ' << right << ' ' << winCnt << endl;
        return left >= winCnt || right >= winCnt || left + right + 1 < winCnt;
    }
private:
    TreeNode* findNode(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) { return root; }
        TreeNode* left = findNode(root->left, val);
        return left == nullptr ? findNode(root->right, val) : left;
    }
    int cntNodes(TreeNode* root) {
        if (root == nullptr) { return 0; }
        return 1 + cntNodes(root->left) + cntNodes(root->right);
    }
};
// @lc code=end

