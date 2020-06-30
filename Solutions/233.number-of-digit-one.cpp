/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */
class Solution {
public:
    int countDigitOne(int n) {
        int ans(0);

        long long int head(0), now(0), tail(0);
        for (long long int d(1); d <= n; d *= 10)
        {
            head = n / d / 10;
            now = n / d % 10;
            tail = n % d;
            ans += head * d;
            if (now == 1) ans += tail + 1;
            else if (now > 1) ans += d;
        }

        return ans;
    }
};

