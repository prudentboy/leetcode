/*
 * @lc app=leetcode id=1238 lang=cpp
 *
 * [1238] Circular Permutation in Binary Representation
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        for (int i(0); i < (1 << n); ++i) {
            ans[i] = start ^ i ^ (i >> 1);
        }
        return ans;
    }
};
// @lc code=end

