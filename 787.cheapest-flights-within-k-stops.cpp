/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> prices(n, vector<int>(n, -1));
        for (const auto& f : flights) {
            prices[f[0]][f[1]] = f[2];
        }

        int ans(INT_MAX);
        vector<int> minPrice(n, -1);
        minPrice[src] = 0;
        queue<int> q;
        q.push(src);
        int i(0), len(0), tmp(0);
        while (K-- >= 0 && !q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                for (i = 0; i < n; ++i) {
                    if (prices[tmp][i] < 0) continue;
                    if (minPrice[i] == -1 || minPrice[tmp] + prices[tmp][i] < minPrice[i]) {
                        if (K >= 0 || i == dst) {
                            minPrice[i] = minPrice[tmp] + prices[tmp][i];
                            q.push(i);
                            if (i == dst) ans = min(ans, minPrice[i]);
                            //cout << tmp << ' ' << i << ' ' << minPrice[i] << endl;
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

