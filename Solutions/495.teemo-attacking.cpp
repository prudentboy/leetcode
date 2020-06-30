/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        
        int ans(0), now(0);

        for (int n : timeSeries)
        {
            ans += duration;
            if (n < now) ans -= (now - n);
            now = n + duration;
        }

        return ans;
    }
};
// @lc code=end

