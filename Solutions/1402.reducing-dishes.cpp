/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());

        int ans(0);
        int cur(0);
        for (int satis : satisfaction) {
            cur += satis;
            if (cur <= 0) { break; }
            ans += cur;
        }
        return ans;
    }
};
// @lc code=end

