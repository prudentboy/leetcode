/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n(arr.size()), mx(arr.back());
        vector<int> ans(n, 0);
        ans[n - 1] = -1;
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = mx;
            mx = max(mx, arr[i]);
        }
        return ans;
    }
};
// @lc code=end

