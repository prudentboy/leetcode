/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int n(A.size());

        vector<int> prefixSum(n + 1);
        for (int i(0); i < n; ++i) { prefixSum[i + 1] = prefixSum[i] + A[i]; }

        int ans(n + 1);
        deque<int> dq;
        for (int i(0); i <= n; ++i) {
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= K) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) { dq.pop_back(); }
            dq.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
// @lc code=end

