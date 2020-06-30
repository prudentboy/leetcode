/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int mx(0), ans(0);
        for (int i(0); i < A.size(); ++i) {
            ans = max(ans, mx + A[i] - i);
            mx = max(mx, A[i] + i);
        }
        return ans;
    }
};
// @lc code=end
