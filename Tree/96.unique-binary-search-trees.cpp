/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // base case:
        if (n < 0) { return 0; }
        if (n <= 1) { return 1; }

        // math method:
        long long int ans(1);
        for (int i(n + 1); i <= (n << 1); ++i) {
            ans *= i;
            ans /= i - n;
        }
        return ans / (n + 1);

        // iter from base case
        vector<int> arr(n + 1, 0);
        arr[0] = arr[1] = 1;
        for (int i(2); i <= n; ++i) {
            for (int j(0); j <= i - 1; ++j) {
                arr[i] += arr[j] * arr[i - 1 - j];
            }
        }
        return arr[n];
    }
};
// @lc code=end

