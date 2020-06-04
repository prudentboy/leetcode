/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);

        int i(0), j(0);
        for (auto& p : paths) {
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }

        vector<int> ans(N, 0);
        for (i = 0; i < N; ++i) {
            vector<int> color(5, 0);
            for (int g : graph[i]) {
                ++color[ans[g]];
            }
            for (j = 1; j < 5; ++j) {
                if (color[j] == 0) {
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

