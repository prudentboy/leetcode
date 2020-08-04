/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        constexpr int M = 1000000007;

        map<int, vector<vector<int>>> posMap;
        for (auto& rec : rectangles) {
            // start mark as 1, end mark as -1
            posMap[rec[0]].push_back({rec[1], 1});
            posMap[rec[0]].push_back({rec[3], -1});
            posMap[rec[2]].push_back({rec[1], -1});
            posMap[rec[2]].push_back({rec[3], 1});
        }

        long ans(0);
        int pre(0), h(0);
        map<int, int> colMap;
        for (auto& pos : posMap) {
            ans += (long)(pos.first - pre) * h;
            ans %= M;
            for (auto& p : pos.second) { colMap[p[0]] += p[1]; }
            int cnt(0), start(0);
            h = 0;
            for (auto& p : colMap) {
                if (cnt == 0) { start = p.first; }
                cnt += p.second;
                if (cnt == 0) { h += p.first - start; }
            }
            pre = pos.first;
            //cout << pos.first << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end
