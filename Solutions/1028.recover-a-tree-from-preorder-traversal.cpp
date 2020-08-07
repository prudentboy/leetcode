/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int, int>> nodes;
        int cnt(0), num(0);
        for (int i(0); i <= S.size(); ++i) {
            if (i == S.size() || S[i] == '-') {
                if (num > 0) {
                    nodes.push_back({cnt, num});
                    cnt = num = 0;
                }
                ++cnt;
            } else {
                num *= 10;
                num += S[i] - '0';
            }
        }
        return recoverFromPreorder(nodes, 0, nodes.size() - 1);
    }
private:
    TreeNode* recoverFromPreorder(const vector<pair<int, int>>& nodes, int beg, int end) {
        if (beg > end) { return nullptr; }
        if (beg == end) { return new TreeNode(nodes[beg].second); }
        TreeNode* root(new TreeNode(nodes[beg].second));
        int cur(nodes[beg].first);
        int right_idx(0);
        for (right_idx = beg + 2; right_idx <= end; ++right_idx) {
            if (nodes[right_idx].first == cur + 1) { break; }
        }
        root->left = recoverFromPreorder(nodes, beg + 1, right_idx - 1);
        root->right = recoverFromPreorder(nodes, right_idx, end);
        return root;
    }
};
// @lc code=end

