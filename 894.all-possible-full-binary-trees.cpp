/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    vector<TreeNode*> allPossibleFBT(int N) {
        unordered_map<int, vector<TreeNode*>> m;
        return allPossibleFBT(N, m);
    }
private:
    vector<TreeNode*> allPossibleFBT(int N, unordered_map<int, vector<TreeNode*>>& m) {
        if ((N & 1) == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        if (m.count(N)) return m[N];
        
        vector<TreeNode*> ans;
        vector<TreeNode*> left, right;
        for (int i(1); i < N; i += 2) {
            left.clear();
            left = allPossibleFBT(i, m);
            right.clear();
            right = allPossibleFBT(N - i - 1, m);
            for (auto& l : left) {
                for (auto& r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        m[N] = ans;
        return ans;
    }
};
// @lc code=end

