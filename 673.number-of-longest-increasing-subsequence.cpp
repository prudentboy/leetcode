/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int ans(1);
        int i(0), j(0);
        int mx(1), n(nums.size());
        vector<int> v(n, 1), c(n, 1);
        for (i = 1; i < n; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                if (nums[i] <= nums[j]) continue;
                if (v[i] > v[j] + 1) continue;
                if (v[i] == v[j] + 1) c[i] += c[j];
                else
                {
                    c[i] = c[j];
                    v[i] = v[j] + 1;
                }
                //cout << i << ' ' << j << ' ' << v[j] << ' ' << c[i] << ' ' << v[i] << endl; 
            }
            if (v[i] < mx) continue;
            if (v[i] == mx) ans += c[i];
            else
            {
                mx = v[i];
                ans = c[i];
            }
            //cout << i << ' ' << mx << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

