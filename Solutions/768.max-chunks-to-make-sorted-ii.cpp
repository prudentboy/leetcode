/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n(arr.size());
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int l, int r) {
            if (arr[l] == arr[r]) { return l < r; }
            return arr[l] < arr[r];
        });

        int ans(0);
        int mx(0);
        for (int i(0); i < n; ++i) {
            mx = max(v[i], mx);
            if (i == mx) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

