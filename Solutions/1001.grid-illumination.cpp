/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */

// @lc code=start
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_set<long> lampPos;
        unordered_map<int, int> row, col;
        unordered_map<long, int> left, right;
        for (auto& lamp : lamps) {
            int x(lamp[0]), y(lamp[1]);
            lampPos.insert((long)x << 32 | y);
            ++row[x];
            ++col[y];
            ++left[x + y];
            ++right[x - y];
        }

        const vector<vector<int>> dir({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});
        vector<int> ans(queries.size());
        for (int i(0); i < queries.size(); ++i) {
            int x(queries[i][0]), y(queries[i][1]);
            if (row[x] > 0 || col[y] > 0 || left[x + y] > 0 || right[x - y] > 0) { ans[i] = 1; }
            for (int j(0); j < 9; ++j) {
                int nx(x + dir[j][0]), ny(y + dir[j][1]);
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || lampPos.count((long)nx << 32 | ny) == 0) { continue; }
                lampPos.erase((long)nx << 32 | ny);
                --row[nx];
                --col[ny];
                --left[nx + ny];
                --right[nx - ny];
            }
        }

        return ans;
    }
};
// @lc code=end

