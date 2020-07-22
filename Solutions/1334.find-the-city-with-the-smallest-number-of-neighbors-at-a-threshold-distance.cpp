/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, distanceThreshold + 1));
        int i(0), j(0), k(0);
        for (i = 0; i < n; ++i) { dis[i][i] = 0; }
        for (auto& edge : edges) {
            dis[edge[0]][edge[1]] = edge[2];
            dis[edge[1]][edge[0]] = edge[2];
        }

        for (k = 0; k < n; ++k) {
            for (i = 0; i < n; ++i) {
                for (j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int mn(n), ans(-1), cnt(0);
        for (i = 0; i < n; ++i) {
            cnt = 0;
            for (j = 0; j < n; ++j) {
                if (i == j) { continue; }
                if (dis[i][j] <= distanceThreshold) { ++cnt; }
                if (cnt > mn) { break; }
            }
            if (j == n) {
                mn = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end

