/*
 * @lc app=leetcode id=1222 lang=cpp
 *
 * [1222] Queens That Can Attack the King
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        const vector<vector<int>> dir({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});

        vector<int> pos(64);
        for (auto& queen : queens) { pos[queen[0] * 8 + queen[1]] = 1; }

        vector<vector<int>> ans;

        int x(0), y(0), cnt(0);
        for (int i(0); i < 8; ++i) {
            cnt = 0;
            while (cnt++ < 8) {
                x = king[0] + dir[i][0] * cnt;
                y = king[1] + dir[i][1] * cnt;
                if (x < 0 || x > 7 || y < 0 || y > 7) { break; }
                if (pos[x * 8 + y] == 1) {
                    ans.push_back({x, y});
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

