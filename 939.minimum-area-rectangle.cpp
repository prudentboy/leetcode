/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// @lc code=start
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> s;
        for (auto& p : points) {
            s.insert(genKey(p));
        }
        int i(0), j(0), n(points.size());
        int ans(INT_MAX);
        for (i = 0; i < n - 1; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) { continue; }
                if (s.count(genKey(points[i][0], points[j][1])) == 0 || s.count(genKey(points[j][0], points[i][1])) == 0) { continue;}
                ans = min(ans, abs((points[i][0] - points[j][0]) * (points[i][1] - points[j][1])));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
private:
    inline int genKey(const vector<int>& v) {
        return genKey(v[0], v[1]);
    }
    inline int genKey(int x, int y) {
        return x * 40001 + y;
    }
};
// @lc code=end

