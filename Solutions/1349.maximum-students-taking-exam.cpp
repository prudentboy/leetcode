/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 */

// @lc code=start
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        const int m(seats.size()), n(seats[0].size());
        vector<vector<int>> dp(m + 1, vector<int>(1 << n));
        vector<int> states, nxt;
        unordered_set<int> ust;
        states.emplace_back(0);

        for (int i(1); i <= m; ++i) {
            vector<int> curStates(getPossibleStates(seats[i - 1]));
            ust.clear();
            for (int state : states) {
                for (int cur : curStates) {
                    if (((state >> 1) & cur) > 0 || (state & (cur >> 1)) > 0) { continue; }
                    ust.insert(cur);
                    dp[i][cur] = max(dp[i][cur], dp[i - 1][state] + __builtin_popcount(cur));
                }
            }
            states.clear();
            for (int num : ust) { states.emplace_back(num); }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
private:
    vector<int> getPossibleStates(const vector<char>& seat) {
        vector<int> ret;
        function<void(int, int)> dfs = [&](int idx, int cur) {
            if (idx == seat.size()) {
                ret.push_back(cur);
                return;
            }
            dfs(idx + 1, cur << 1);
            if (seat[idx] == '#' || (cur & 1) == 1) { return; }
            dfs(idx + 1, (cur << 1) + 1);
        };
        dfs(0, 0);
        return ret;
    }
};
// @lc code=end

