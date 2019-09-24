/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n, 1);
        vector<int> index(primes.size(), 0);

        int min(0);
        int i(1), j(1);
        for (; i < n; ++i)
        {
            min = ans[index[0]] * primes[0];
            for (j = 1; j < primes.size(); ++j)
            {
                if (min > ans[index[j]] * primes[j]) min = primes[j] * ans[index[j]];
            }
            ans[i] = min;
            for (j = 0; j < index.size(); ++j)
            {
                if (ans[index[j]] * primes[j] == min) ++index[j];
            }
        }

        return ans.back();
    }
};

