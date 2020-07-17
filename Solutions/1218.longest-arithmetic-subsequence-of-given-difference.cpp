/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans(0);

        unordered_map<int, int> ump;
        for (int num : arr) {
            ump[num] = ump[num - difference] + 1;
            ans = max(ans, ump[num]);
        }

        return ans;
    }
};
// @lc code=end

