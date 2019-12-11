/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
public:
    double soupServings(int N) {
        if (N > 5000) return 1.0;
        unordered_map<string, double> m;
        return soupServings(N, N, m);
    }
private:
    double soupServings(int A, int B, unordered_map<string, double>& m) {
        string key(to_string(A).append("|").append(to_string(B)));
        if (m.count(key) > 0) return m[key];
        double ans(0.0);
        if (A <= 0 && B <= 0) ans = 0.5;
        else if (B <= 0) ans = 0.0;
        else if (A <= 0) ans = 1.0;
        else {
            ans += 0.25 * soupServings(A - 100, B, m);
            ans += 0.25 * soupServings(A - 75, B - 25, m);
            ans += 0.25 * soupServings(A - 50, B - 50, m);
            ans += 0.25 * soupServings(A - 25, B - 75, m);
        }
        m[key] = ans;
        return ans;
    }
};
// @lc code=end

