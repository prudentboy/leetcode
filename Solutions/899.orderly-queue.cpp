/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        int n(S.size());
        S.append(S);
        string_view str(S);
        int mn(0);
        for (int j(1); j <= n; ++j) {
            if (str.substr(j, n) < str.substr(mn, n)) { mn = j; }
        }
        //cout << mn << endl;

        return string(str.substr(mn, n));
    }
};
// @lc code=end

