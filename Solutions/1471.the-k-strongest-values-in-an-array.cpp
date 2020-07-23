/*
 * @lc app=leetcode id=1471 lang=cpp
 *
 * [1471] The k Strongest Values in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n(arr.size()), med(arr[(n - 1) >> 1]);
        int i(0), j(n - 1);
        vector<int> ans(k);
        for (int& x : ans) {
            x = med - arr[i] > arr[j] - med ? arr[i++] : arr[j--];
        }
        return ans;
    }
};
// @lc code=end

