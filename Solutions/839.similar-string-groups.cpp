/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n(A.size());
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);

        function<int(int)> find = [&](int idx) -> int {
            if (parents[idx] != idx) { parents[idx] = find(parents[idx]); }
            return parents[idx];
        };

        for (int i(0); i < n; ++i) {
            for (int j(0); j < n; ++j) {
                if (i == j) { continue; }
                if (isSimilar(A[i], A[j])) {
                    int pi(find(i)), pj(find(j));
                    parents[pi] = pj;
                }
            }
        }

        int ans(0);
        for (int i(0); i < n; ++i) {
            if (parents[i] == i) { ++ans; }
        }
        return ans;
    }
private:
    bool isSimilar(string_view s1, string_view s2) {
        int cnt(0);
        for (int i(0); i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (++cnt > 2) { return false; }
            }
        }
        return true;
    }
};
// @lc code=end

