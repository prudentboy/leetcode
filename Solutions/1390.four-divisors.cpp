/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans(0);
        for (int n : nums) {
            if (n == 1) { continue; }
            int r(sqrt(n));
            if (r * r == n) { continue; }
            int sum(n + 1);
            int i(0);
            for (i = 2; i <= r; ++i) {
                if (n % i != 0) { continue; }
                if (sum > n + 1) { break; }
                sum += i + n / i;
            }
            if (i > r && sum > n + 1) { ans += sum; }
            //cout << n << ' ' << sum << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

