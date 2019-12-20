/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        getTreeGraph(root, m);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        int len(0);
        TreeNode* tmp(nullptr);
        while (K-- > 0) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                visited.insert(tmp);
                for (auto& node : m[tmp]) {
                    if (visited.count(node) > 0) { continue; }
                    q.push(node);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);
        }
        return ans;
    }
private:
    void getTreeGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& m) {
        if (root == nullptr) { return; }
        if (root->left != nullptr) {
            m[root].push_back(root->left);
            m[root->left].push_back(root);
            getTreeGraph(root->left, m);
        }
        if (root->right != nullptr) {
            m[root].push_back(root->right);
            m[root->right].push_back(root);
            getTreeGraph(root->right, m);
        }
    }
};
// @lc code=end

