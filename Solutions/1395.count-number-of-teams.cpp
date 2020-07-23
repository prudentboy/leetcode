/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans(0);
        int left(0), right(0);
        int i(0), j(0), n(rating.size());
        for (i = 1; i < n - 1; ++i) {
            left = right = 0;
            for (j = 0; j < i; ++j) { if (rating[j] > rating[i]) { ++left; } }
            for (j = i + 1; j < n; ++j) { if (rating[j] > rating[i]) { ++right; } }
            ans += left * (n - i - 1 - right);
            ans += (i - left) * right;
            //cout << i << ' ' << left << ' ' << right << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

