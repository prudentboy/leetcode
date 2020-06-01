/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(const vector<int>& preorder, int pBeg, int pEnd, const vector<int>& inorder, int iBeg, int iEnd) {
        //cout << pBeg << ' ' << pEnd << ' ' << iBeg << ' ' << iEnd << endl;
        // corner case
        if (pBeg > pEnd || iBeg > iEnd) { return nullptr; }

        TreeNode* ans(new TreeNode(preorder[pBeg]));
        int i(iBeg);
        for (; i <= iEnd; ++i) {
            if (inorder[i] == preorder[pBeg]) {
                break;
            }
        }
        ans->left = buildTree(preorder, pBeg + 1, pBeg + i - iBeg, inorder, iBeg, i - 1);
        ans->right = buildTree(preorder, pBeg + i + 1 - iBeg, pEnd, inorder, i + 1, iEnd);
        return ans;
    }
};
// @lc code=end

