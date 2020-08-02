/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n(A.size());
        if (n < 2) { return false; }

        int sum(accumulate(A.begin(), A.end(), 0));
        int i(0);
        for (i = 1; i <= (n >> 1); ++i) {
            if (sum * i % n == 0) { break; }
        }
        if (i > (n >> 1)) { return false; }

        vector<unordered_set<int>> dp((n >> 1) + 1);
        dp[0].insert(0);
        for (int num : A) {
            for (i = (n >> 1); i > 0; --i) {
                for (int x : dp[i - 1]) { dp[i].insert(x + num); }
            }
        }

        for (i = 1; i <= (n >> 1); ++i) {
            if (sum * i % n == 0 && dp[i].count(sum * i / n)) { return true; }
        }
        return false;
    }
};
// @lc code=end

