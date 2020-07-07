/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */

// @lc code=start
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n(values.size());
        vector<vector<int>> vlPairs(n, vector<int>(2));
        int i(0);
        for (i = 0; i < n; ++i) {
            vlPairs[i][0] = values[i];
            vlPairs[i][1] = labels[i];
        }

        sort(vlPairs.begin(), vlPairs.end());

        int ans(0);
        unordered_map<int, int> labelUmp;
        i = n - 1;
        while (i >= 0 && num_wanted > 0) {
            if (labelUmp[vlPairs[i][1]] < use_limit) {
                ans += vlPairs[i][0];
                ++labelUmp[vlPairs[i][1]];
                --num_wanted;
            }
            --i;
        }
        return ans;
    }
};
// @lc code=end

