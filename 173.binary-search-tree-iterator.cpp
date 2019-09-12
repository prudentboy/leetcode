/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        Init(root);
        pos = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return vec[pos++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < vec.size();
    }

private:
    void Init(TreeNode* root)
    {
        if (root == nullptr) return;

        Init(root->left);
        vec.push_back(root->val);
        Init(root->right);
    }

private:
    vector<int> vec;
    size_t pos;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

