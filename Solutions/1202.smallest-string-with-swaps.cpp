/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n(s.size());

        // Union Find
        int i(0);
        vector<int> parents(n);
        for (i = 0; i < n; ++i) { parents[i] = i; }

        function<int(int)> uFind = [&](int idx) {
            if (parents[idx] != idx) {
                parents[idx] = uFind(parents[idx]);
            }
            return parents[idx];
        };

        function<void(int, int)> uUnion = [&](int x, int y) {
            int xParent(uFind(x)), yParent(uFind(y));
            parents[xParent] = yParent;
        };

        // find unions
        for (auto& p : pairs) { uUnion(p[0], p[1]); }

        // sort by unions
        vector<vector<int>> groups(n);
        vector<string> sortStr(n);

        for (i = 0; i < n; ++i) {
            groups[uFind(i)].push_back(i);
            sortStr[uFind(i)] += s[i];
        }

        int j(0);
        for (i = 0; i < n; ++i) {
            if (sortStr[i].empty()) { continue; }
            sort(sortStr[i].begin(), sortStr[i].end());
            for (j = 0; j < groups[i].size(); ++j) {
                s[groups[i][j]] = sortStr[i][j];
            }
        }

        return s;
    }
};
// @lc code=end

