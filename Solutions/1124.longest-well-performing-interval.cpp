/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> ump;
        int ans(0), sum(0);
        for (int i(0); i < hours.size(); ++i) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) { ans = i + 1; }
            if (ump.count(sum) == 0) { ump[sum] = i; }
            if (ump.count(sum - 1) > 0) { ans = max(ans, i - ump[sum - 1]); }
        }
        return ans;
    }
};
// @lc code=end

