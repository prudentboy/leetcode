/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */

// @lc code=start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int cpy(label);
        int level(0);
        while (cpy > 0) {
            ++level;
            cpy >>= 1;
        }
        vector<int> ans(level--, label);
        while (level > 0) {
            label >>= 1;
            label = 3 * (1 << level - 1) - 1 - label;
            ans[--level] = label;
        }
        return ans;
    }
};
// @lc code=end

