/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        const int n(arr.size());
        if (n == 1) { return arr.front().front(); }

        int mn(0), nxt(0);
        vector<int> dp(arr.front());
        for (int i(1); i < n; ++i) {
            vector<int> cur(dp);
            get2Min(cur, mn, nxt);
            for (int j(0); j < n; ++j) { cur[j] = (dp[j] == mn ? nxt : mn) + arr[i][j]; }
            swap(dp, cur);
        }
        return *min_element(dp.begin(), dp.end());
    }
private:
    void get2Min(const vector<int>& line, int& mn, int& nxt) {
        mn = nxt = INT_MAX;
        for (int num : line) {
            if (num < mn) {
                nxt = mn;
                mn = num;
            } else if (num < nxt) {
                nxt = num;
            }
        }
    }
};
// @lc code=end

