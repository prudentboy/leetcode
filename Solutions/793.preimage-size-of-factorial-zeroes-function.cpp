/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int K) {
        if (K < 5) { return 5; }
        int base(1);
        while (base * 5 + 1 <= K) {
            base = base * 5 + 1;
        }
        if (K / base == 5) { return 0; }
        return preimageSizeFZF(K % base);
    }
/*
        //if (K < 5) { return 5; }
        if (K == 1000000000) { return 5; }
        return helper(K + 1) - helper(K);
    }
private:
    int helper(int K) {
        long long int left(0), mid(0), right(LONG_MAX);
        while (left <= right) {
            mid = left + ((right - left) / 2);
            int n(cntTrailingZeros(mid));
            if (n >= K) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    long long int cntTrailingZeros(int n) {
        if (n < 5) { return 0; }
        return n / 5 + cntTrailingZeros(n / 5);
    }
*/
};
// @lc code=end

