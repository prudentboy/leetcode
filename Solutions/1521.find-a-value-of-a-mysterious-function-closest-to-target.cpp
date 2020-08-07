/*
 * @lc app=leetcode id=1521 lang=cpp
 *
 * [1521] Find a Value of a Mysterious Function Closest to Target
 */

// @lc code=start
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans(INT_MAX);
        vector<int> candidates;
        for (int num : arr) {
            ans = min(ans, abs(num - target));
            vector<int> tmp;
            tmp.push_back(num);
            for (int candidate : candidates) {
                int cur(num & candidate);
                ans = min(ans, abs(cur - target));
                tmp.push_back(cur);
            }
            candidates.clear();
            for (int i(0); i < tmp.size(); ++i) {
                if (i == 0 || tmp[i] != tmp[i - 1]) { candidates.push_back(tmp[i]); }
            }
        }
        return ans;
    }
};
// @lc code=end

