/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) return ans;

        std::queue<TreeNode*> q_tree;
        q_tree.push(root);

        int len(1);
        TreeNode* tmp;
        std::vector<int> layer;
        while (not q_tree.empty())
        {
            tmp = q_tree.front();
            q_tree.pop();
            if (tmp->left != nullptr) q_tree.push(tmp->left);
            if (tmp->right != nullptr) q_tree.push(tmp->right);
            layer.push_back(tmp->val);

            if (layer.size() == len)
            {
                if (ans.size() % 2 == 1 and layer.size() > 1)
                {
                    reverse(layer.begin(), layer.end());
                }
                ans.push_back(layer);
                layer.clear();
                len = q_tree.size();                
            }
        }

        return ans;
    }
};

