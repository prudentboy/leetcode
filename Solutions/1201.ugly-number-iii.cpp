/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if (a > c) { swap(a, c); }
        if (b > c) { swap(b, c); }
        if (b < a) { swap(a, b); }
        
        auto check = [&](long long int tempt) -> bool {
            long long int cnt(0);
            cnt += (tempt / a + tempt / b + tempt / c);
            cnt -= (tempt / lcm(a, b) + tempt / lcm(a, c) + tempt / lcm(b, c));
            cnt += tempt / lcm(a, b, c);
            return cnt >= n;
        };
        long long int left(a), right((long long int)c * n), mid(0);
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    long long int lcm(const long long int x, const long long int y) {
        return x * y / gcd(x, y);
    }
    long long int lcm(const int x, const int y, const int z) {
        return lcm(x, lcm(y, z));
    }
    int gcd(const int small, const int big) const {
        if (big % small == 0) { return small; }
        return gcd(big % small, small);
    }
    int gcd(const int x, const int y, const int z) {
        const int tmp(gcd(x, y));
        return tmp > z ? gcd(z, tmp) : gcd(tmp, z);
    }
};
// @lc code=end

