/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans(0);
        int i(0), j(0), mx(0);
        int n(profit.size()), m(worker.size());
        vector<pair<int, int>> v(n);
        for (i = 0; i < n; ++i) {
            v[i] = {difficulty[i], profit[i]};
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        i = 0;
        for (j = 0; j < m; ++j) {
            if (worker[j] < v[i].first) {
                ++i;
            }
            while (i < n && worker[j] >= v[i].first) {
                mx = max(mx, v[i].second);
                ++i;
            }
            ans += mx;
            --i;
        }
        return ans;
    }
};
// @lc code=end

