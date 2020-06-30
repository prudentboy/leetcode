/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        const array<int, 3> primes({2,3,5});
        vector<int> index(3, 0);
        vector<int> ans(n, 1);

        int i(1), j(1), min(0);
        for (; i < n; ++i)
        {
            min = ans[index[0]] * primes[0];
            for (j = 1; j < 3; ++j) if (ans[index[j]] * primes[j] < min) min = ans[index[j]] * primes[j];
            ans[i] = min;
            for (j = 0; j < 3; ++j)
            {
                if (ans[index[j]] * primes[j] == min) ++index[j];
            }
        }

        return ans.back();
    } 
};

