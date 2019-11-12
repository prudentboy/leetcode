/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (55.88%)
 * Likes:    459
 * Dislikes: 91
 * Total Accepted:    57.1K
 * Total Submissions: 102.1K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == nullptr) return {};
        int maxCnt(1);
        unordered_map<int, int> m;
        cntTreeSum(root, m, maxCnt);
        
        vector<int> ans;
        for (const auto& p : m)
        {
            if (p.second < maxCnt) continue;
            ans.push_back(p.first);
        }
        return ans;
    }
private:
    int cntTreeSum(TreeNode* root, unordered_map<int, int>& m, int& max)
    {
        if (root == nullptr) return 0;

        int left(cntTreeSum(root->left, m, max));
        int right(cntTreeSum(root->right, m, max));
        int val(left + right + root->val);
        ++m[val];
        if (m[val] > max) max = m[val];
        return val;
    }
};
// @lc code=end

