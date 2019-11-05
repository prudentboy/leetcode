/*
 * @lc app=leetcode id=483 lang=cpp
 *
 * [483] Smallest Good Base
 */

// @lc code=start
class Solution {
public:
    string smallestGoodBase(string n) {
        long long int N(stoll(n));
        long long int k(0), a(0);
        for (k = log(N + 1) / log(2); k > 0; --k)
        {
            a = int(pow(N, 1.0 / k));
            //cout << k << ' ' << a << ' ' << (pow(a, k + 1) - 1) / (a - 1) - N << endl;
            if (abs((pow(a, k + 1) - 1) / (a - 1) - N) < N * 1e-15 && a > 1) return to_string(a);
        }
        return to_string(N - 1);
    }
};
// @lc code=end

