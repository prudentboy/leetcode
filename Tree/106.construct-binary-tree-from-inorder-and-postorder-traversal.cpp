/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* buildTree(const vector<int>& inorder, int iBeg, int iEnd, const vector<int>& postorder, int pBeg, int pEnd) {
        //corner case
        if (iBeg > iEnd || pBeg > pEnd) { return nullptr; }

        TreeNode* ans(new TreeNode(postorder[pEnd]));
        int i(iBeg);
        for (; i <= iEnd; ++i) {
            if (inorder[i] == postorder[pEnd]) { break; }
        }

        ans->left = buildTree(inorder, iBeg, i - 1, postorder, pBeg, pBeg - iBeg + i - 1);
        ans->right = buildTree(inorder, i + 1, iEnd, postorder, pBeg - iBeg + i, pEnd - 1);
        
        return ans;
    }
};
// @lc code=end

