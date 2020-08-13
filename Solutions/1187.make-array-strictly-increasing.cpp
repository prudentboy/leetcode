/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

        const int m(arr1.size()), n(arr2.size()), kInf(10000);
        vector<int> keep(m, kInf);
        vector<vector<int>> change(m, vector<int>(n, kInf));

        keep[0] = 0;
        for (int i(0); i < n; ++i) { change[0][i] = 1; }

        int mn_keep(0), mn_change(0);
        for (int i(1); i < m; ++i) {
            mn_keep = mn_change = kInf;
            if (arr1[i] > arr1[i - 1]) { keep[i] = keep[i - 1]; }
            for (int j(0); j < n; ++j) {
                if (arr1[i] > arr2[j]) { mn_keep = min(mn_keep, change[i - 1][j]); }
                change[i][j] = min(change[i][j], mn_change + 1);
                mn_change = min(mn_change, change[i - 1][j]);
                if (arr2[j] > arr1[i - 1]) { change[i][j] = min(change[i][j], keep[i - 1] + 1); }
                //cout << i << ' ' << j << ' ' << change[i][j] << ' ' << endl;
            }
            //cout << keep[i] << endl;
            keep[i] = min(keep[i], mn_keep);
        }

        int ans(keep.back());
        for (int i(0); i < n; ++i) { ans = min(ans, change[m - 1][i]); }
        return ans >= kInf ? -1 : ans;
    }
};
// @lc code=end

