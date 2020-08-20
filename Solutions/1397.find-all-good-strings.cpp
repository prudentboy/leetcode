/*
 * @lc app=leetcode id=1397 lang=cpp
 *
 * [1397] Find All Good Strings
 */

// @lc code=start
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        // const paras
        const int m(evil.size()), kMod(1e9 + 7);

        // kmp pretreat
        vector<int> next(2, 0);
        for (int i(1), j(0); i < m; ++i) {
            while (j > 0 && evil[i] != evil[j]) { j = next[j]; }
            if (evil[i] == evil[j]) { ++j; }
            next.emplace_back(j);
        }

        // get next state: kmp next index
        vector<vector<int>> evil_memo(m, vector<int>(26, -1));
        auto getNxtState = [&](int state, char c) -> int {
            if (evil_memo[state][c - 'a'] != -1) { return evil_memo[state][c - 'a']; }
            int nxt(state);
            while (nxt > 0 && evil[nxt] != c) { nxt = next[nxt]; }
            if (evil[nxt] == c) { ++nxt; }
            return evil_memo[state][c - 'a'] = nxt;
        };

        // get next bound: 0-any, 1-upper, 2-lower, 3-upper&lower
        auto getNxtBound = [&](int bound, char upper, char lower, char cur) -> int {
            if (bound == 0) { return 0; }
            int ret(0);
            if ((bound & 1) > 0 && cur == upper) { ret |= 1; }
            if ((bound & 2) > 0 && cur == lower) { ret |= 2; }
            return ret;
        };

        // main loop : dp
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(4, -1)));
        function<int(int, int, int)> dp = [&](int pos, int state, int bound) -> int {
            if (state == m) { return 0; }
            if (pos == n) { return 1; }
            if (memo[pos][state][bound] != -1) { return memo[pos][state][bound]; }

            int& ret(memo[pos][state][bound]);
            ret = 0;
            char upper((bound & 1) > 0 ? s2[pos] : 'z'), lower((bound & 2) > 0 ? s1[pos] : 'a');
            for (char cur(lower); cur <= upper; ++cur) {
                int nxtState(getNxtState(state, cur));
                int nxtBound(getNxtBound(bound, s2[pos], s1[pos], cur));
                ret += dp(pos + 1, nxtState, nxtBound);
                ret %= kMod;
            }

            return ret;
        };

        return dp(0, 0, 3);
    }
};
// @lc code=end
