/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n(arr.size());
        if (n < 2) return 0;
        
        vector<int> acc(n + 1);
        int i(0), j(0);
        for (i = 1; i <= n; ++i) { acc[i] = acc[i - 1] ^ arr[i - 1]; }
        
        auto calAcc = [&](int beg, int end) -> int {
            return acc[end + 1] ^ acc[beg];
        };

        int ans(0);

        for (i = 0; i < n - 1; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (acc[i] == acc[j + 1]) { ans += j - i; }
            }
        }

        return ans;
    }
};
// @lc code=end

