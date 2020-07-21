/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i(0), j(0), n(arr.size());
        int thr(k * threshold), ans(0), sum(0);
        for (i = 0; i < n; ++i) {
            sum += arr[i];
            if (i - j >= k) { sum -= arr[j++]; }
            if (i - j + 1 == k && sum >= thr) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

