/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Numbers With Repeated Digits
 */

// @lc code=start
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<vector<int>> memo(10, vector<int>(10, -1));
        function<int(int, int)> calAmn = [&](int m, int n) {
            if (memo[m][n] != -1) { return memo[m][n]; }
            if (n == 0) { return 1; }
            if (n == 1) { return memo[m][n] = m; }
            return memo[m][n] = m * calAmn(m - 1, n - 1);
        };

        int cpy(N);
        vector<int> digits;
        while (cpy > 0) {
            digits.emplace_back(cpy % 10);
            cpy /= 10;
        }
        reverse(digits.begin(), digits.end());

        int noRep(0), tmp(0);
        for (int i(digits.size() - 1); i > 0; --i) { noRep += 9 * calAmn(9, i - 1); }

        vector<int> used(10);
        for (int i(0); i < digits.size(); ++i) {
            tmp = digits[i];
            for (int j(i == 0); j < digits[i]; ++j) {
                if (used[j] > 0) { continue; }
                noRep += calAmn(9 - i, digits.size() - i - 1);
            }
            if (++used[tmp] > 1) { break; }
            if (i == digits.size() - 1) { ++noRep; }
        }
        return N - noRep;
    }
private:
    int calAmn(int m, int n) {
        int ret(m);
        while (n-- > 0) { ret *= --m; }
        return ret;
    }
};
// @lc code=end

