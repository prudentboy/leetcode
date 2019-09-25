/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int first(0), second(1), third(1), tmp(0);

        for (int i(3); i <= n; ++i)
        {
            tmp = first + second + third;
            first = second;
            second = third;
            third = tmp;
        }

        return third;
    }
};

