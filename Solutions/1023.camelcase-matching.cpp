/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n(queries.size());
        vector<bool> ans(n, false);

        for (int i(0); i < n; ++i) { ans[i] = check(queries[i], pattern); }

        return ans;
    }
private:
    bool check(const string& q, const string& p) {
        int i(0), j(0);

        while (i < q.size() && j < p.size()) {
            if (q[i] == p[j]) {
                ++i;
                ++j;
            } else if (q[i] <= 'z' && q[i] >= 'a') {
                ++i;
            } else {
                break;
            }
        }

        while (i < q.size()) {
            if (q[i] <= 'z' && q[i] >= 'a') {
                ++i;
            } else {
                break;
            }
        }

        return i == q.size() && j == p.size();
    }
};
// @lc code=end

