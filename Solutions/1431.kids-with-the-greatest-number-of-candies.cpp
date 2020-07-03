/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n(candies.size());
        vector<bool> ans(n, false);
        int mx(0);
        for (int candy : candies) { mx = max(mx, candy); }
        for (int i(0); i < n; ++i) {
            if (candies[i] + extraCandies >= mx) { ans[i] = true; }
        }
        return ans;
    }
};
// @lc code=end

