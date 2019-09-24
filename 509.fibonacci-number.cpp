/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
class Solution {
public:
    int fib(int N) {
        std::vector<int> arr(N + 1, 0);
        if (N == 0) return 0;
        arr[1] = 1;
        for (size_t i(2); i <= N; ++i)
        {
            arr[i] = arr[i - 2] + arr[i - 1];
        }
        return arr[N];
    }
};

