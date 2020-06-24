/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if (N == 0) { return ans; }
        if (N == 1) { ans.push_back(0); }
        for (int i(1); i < 10; ++i) {
            backtrace(N, K, i, 1, ans);
        }
        return ans;
    }
private:
    void backtrace(int N, int K, int now, int cnt, vector<int>& ans) {
        if (cnt == N) {
            ans.push_back(now);
            return;
        }

        if (now % 10 + K < 10) {
            now = now * 10 + now % 10 + K;
            backtrace(N, K, now, cnt + 1, ans);
            now /= 10;
        }

        if (K > 0 && now % 10 - K >= 0) {
            now = now * 10 + now % 10 - K;
            backtrace(N, K, now, cnt + 1, ans);
            now /= 10;
        }
    }
};
// @lc code=end

