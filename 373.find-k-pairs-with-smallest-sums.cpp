/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        ans.reserve(k);

        int i(0), j(0);
        int m(min(k, (int)nums1.size())), n(min(k, (int)nums2.size()));
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                ans.push_back({nums1[i], nums2[j]});
            }
        }

        sort(ans.begin(), ans.end(), [](vector<int>& l, vector<int>& r){return l[0] + l[1] < r[0] + r[1];});
        if (ans.size() > k) ans.resize(k);

        return ans;
    }
};
// @lc code=end

