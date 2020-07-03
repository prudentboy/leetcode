/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 */

// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo(2, 1);
        fibo.reserve(50);

        int cnt(2);
        while (fibo.back() < k) {
            fibo.push_back(fibo[cnt - 1] + fibo[cnt - 2]);
            ++cnt;
        }

        auto upper = fibo.end();

        function<int(int)> f = [&](int num) {
            if (num == 0) { return 0; }
            upper = upper_bound(fibo.begin(), upper, num);
            return 1 + f(num - *(--upper));
        };
        return f(k);
    }
};
// @lc code=end

