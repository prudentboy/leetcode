/*
 * @lc app=leetcode id=1447 lang=cpp
 *
 * [1447] Simplified Fractions
 */

// @lc code=start
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if (n <= 1) { return {}; }
        
        vector<string> ans;
        ans.reserve(n * n);
        int i(0), j(0);
        string tmp;
        for (i = 2; i <= n; ++i) {
            for (j = 1; j < i; ++j) {
                if (gcd(i, j) == 1) {
                    tmp.assign(to_string(j));
                    tmp += '/';
                    tmp.append(to_string(i));
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
private:
    int gcd(int a, int b) {
        if (a < b) { swap(a, b); }
        if (a % b == 0) { return b; }
        return gcd(b, a % b);
    }
};
// @lc code=end

