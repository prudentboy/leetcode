/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> manstream(1001);
        for (auto& trip : trips) {
            manstream[trip[1]] += trip[0];
            manstream[trip[2]] -= trip[0];
        }

        int cnt(0);
        for (int i(0); i < 1001; ++i) {
            cnt += manstream[i];
            if (cnt > capacity) { return false; }
        }
        return true;
    }
};
// @lc code=end

