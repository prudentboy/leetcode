/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        if (n == 3) return 2;

        int ans(1);
        int ind(1), res(1);
        for (int i(2); i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                ind = n / i;
                res = 1;
            }
            else
            {
                if (i * (n % i) < (n % i + i))
                {
                    ind = n / i - 1;
                    res = n % i + i;
                }
                else
                {
                    ind = n / i;
                    res = n % i;
                }
                
            }
            ans = max(ans, int(pow(i, ind) * res));
        }
        return ans;
    }
};

