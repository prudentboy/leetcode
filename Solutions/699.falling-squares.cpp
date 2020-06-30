/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 */

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int mx(0);
        vector<int> ans;

        vector<vector<int>> now;
        int h(0), start(0), end(0), height(0);
        for (auto& sq : positions) {
            start = sq[0];
            end = sq[1] + start;
            height = sq[1];

            h = 0;
            for (int i = 0; i < now.size(); ++i) {
                if (start >= now[i][1] || end <= now[i][0]) { continue; }
                h = max(h, now[i][2]);
            }
            h += height;
            now.push_back({start, end, h});
            mx = max(mx, h);
            ans.push_back(mx);
        }
        return ans;
    }
};
// @lc code=end

