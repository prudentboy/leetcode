/*
 * @lc app=leetcode id=1366 lang=cpp
 *
 * [1366] Rank Teams by Votes
 */

// @lc code=start
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans(votes[0]);

        int m(votes.size()), n(votes[0].size());
        if (m == 1 || n == 1) { return ans; }

        vector<vector<int>> rank(26, vector<int>(n));
        int i(0);
        for (string& vote : votes) {
            for (i = 0; i < n; ++i) { ++rank[vote[i] - 'A'][i]; }
        }

        sort(ans.begin(), ans.end(), [&](const char& l, const char& r) {
            for (int j(0); j < n; ++j) {
                if (rank[l - 'A'][j] == rank[r - 'A'][j]) { continue; }
                return rank[l - 'A'][j] > rank[r - 'A'][j];
            }
            return l < r;
        });

        return ans;
    }
};
// @lc code=end

