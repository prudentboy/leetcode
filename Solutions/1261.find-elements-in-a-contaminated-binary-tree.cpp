/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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
class FindElements {
public:
    FindElements(TreeNode* root) : root_(recover(root, 0)) {}
    
    bool find(int target) {
        return ust_.count(target) > 0;
    }
private:
    TreeNode* recover(TreeNode* root, int val) {
        if (root == nullptr) { return nullptr; }
        root->val = val;
        ust_.insert(val);
        if (root->left != nullptr) { recover(root->left, (val << 1) + 1); }
        if (root->right != nullptr) { recover(root->right, (val << 1) + 2); }
        return root;
    }
private:
    unordered_set<int> ust_;
    TreeNode* root_;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

