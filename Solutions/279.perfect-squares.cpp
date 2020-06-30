/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 1;
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        int sq(sqrt(n));
        if (sq * sq == n) return 1;
        for (int i(1); i * i < n; ++i)
        {
            int ssq(sqrt(n - i * i));
            if (ssq * ssq == n - i * i) return 2;
        }
        return 3;
    }
};

