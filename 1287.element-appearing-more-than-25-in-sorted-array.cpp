/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i(0), n(arr.size());
        int cnt(1);
        for (i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                ++cnt;
            } else {
                if ((cnt << 2) > n) { return arr[i - 1]; }
                cnt = 1;
            }
        }
        // cout << cnt << ' ' << i << endl;
        if ((cnt << 2) > n) { return arr[i - 1]; }
        return -1;
    }
};
// @lc code=end

