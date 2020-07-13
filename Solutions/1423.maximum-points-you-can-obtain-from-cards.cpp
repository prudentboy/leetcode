/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n(cardPoints.size());
        vector<int> leftWard(n + 1), rightWard(n + 1);
        int i(0);
        for (i = 0; i < n; ++i) { leftWard[i + 1] = leftWard[i] + cardPoints[i]; }
        for (i = 0; i < n; ++i) { rightWard[i + 1] = rightWard[i] + cardPoints[n - i - 1]; }
        
        int ans(0);
        for (i = 0; i <= k; ++i) { ans = max(ans, leftWard[i] + rightWard[k - i]); }
        return ans;
    }
};
// @lc code=end

