/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sort1, sort2;
        inorderTraverse(root1, sort1);
        inorderTraverse(root2, sort2);
        vector<int> ans(sort1.size() + sort2.size());
        merge(sort1, sort2, ans);
        return ans;
    }
private:
    void inorderTraverse(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) { return; }
        inorderTraverse(root->left, vec);
        vec.push_back(root->val);
        inorderTraverse(root->right, vec);
    }
    void merge(const vector<int>& v1, const vector<int>& v2, vector<int>& v) {
        int i(0), j(0), k(0);
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                v[k++] = v1[i++];
            } else {
                v[k++] = v2[j++];
            }
        }
        while (i < v1.size()) { v[k++] = v1[i++]; }
        while (j < v2.size()) { v[k++] = v2[j++]; }
    }
};
// @lc code=end

