/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n(nums.size());
        vector<int> ans(2, 0), flag(n, 0), pos(n, 0);

        vector<pair<int, int>> data;
        int i(0), j(0), cnt(0);
        /*
        while (true) {
            idx = -1;
            mn = INT_MAX;
            for (i = 0; i < n; ++i) {
                if (pos[i] < nums[i].size() && nums[i][pos[i]] < mn) {
                    mn = nums[i][pos[i]];
                    idx = i;
                }
            }
            if (idx >= 0) {
                data.push_back({mn, idx});
                ++pos[idx];
            }
            if (mn == INT_MAX) {
                break;
            }
        }
        */
        for (i = 0; i < n; ++i) {
            for (int n : nums[i]) {
                data.push_back({n, i});
            }
        }
        sort(data.begin(), data.end());
        //cout << data.size() << endl;

        i = j = 0;
        ans[0] = data[0].first;
        ans[1] = data.back().first;
        while (i <= j && j < data.size()) {
            //cout << i << '-' << j << ':' << data[i].first << '-' << data[j].first << endl;
            while (j < data.size()) {
                if (cnt == n) { break; }
                if (flag[data[j].second] == 0) { ++cnt; }
                ++flag[data[j++].second];
            }
            while (i <= j) {
                if (cnt < n) { break; }
                if (data[j - 1].first - data[i].first < ans.back() - ans.front() || \
                    (data[j - 1].first - data[i].first == ans.back() - ans.front() && \
                     data[i].first < ans.front())) {
                    ans[0] = data[i].first;
                    ans[1] = data[j - 1].first;
                }
                if (--flag[data[i++].second] == 0) { --cnt; }
            }
            //cout << ans[0] << ' ' << ans[1] << endl;
        }
        return ans;
    }
};
// @lc code=end

