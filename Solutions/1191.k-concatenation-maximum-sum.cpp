/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int sum(0), now(0), mx1(0), mx2(0);
        
        int n(arr.size());
        for (int i(0); i < (n << 1); ++i) {
            now += arr[i % n];
            if (now < 0) { now = 0; }
            if (i < n) {
                sum += arr[i];
                mx1 = max(mx1, now);
            }
            mx2 = max(mx2, now);
        }

        if (mx1 <= 0) { return 0; }
        if (k == 1) { return mx1; }
        
        return max(sum * (k - 2) + mx2, max(mx1, mx2)) % 1000000007;
    }
};
// @lc code=end

