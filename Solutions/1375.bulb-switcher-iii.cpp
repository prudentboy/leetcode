/*
 * @lc app=leetcode id=1375 lang=cpp
 *
 * [1375] Bulb Switcher III
 */

// @lc code=start
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n(light.size()), ans(0);
        int mx(0), sz(0);
        for (int idx : light) {
            mx = max(mx, idx);
            if (mx == ++sz) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

