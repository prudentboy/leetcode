/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        const string strN(to_string(N));
        
        int i(0);
        string strD(D.size(), ' ');
        for (i = 0; i < D.size(); ++i) { strD[i] = D[i][0]; }

        int ans(0), len(strN.size());

        for (i = 1; i < len; ++i) { ans += pow(strD.size(), i); }

        bool prefix(false);
        for (i = 0; i < len; ++i) {
            prefix = false;
            for (char c : strD) {
                if (c < strN[i]) {
                    ans += pow(strD.size(), len - 1 - i);
                } else if (c == strN[i]) {
                    prefix = true;
                    break;
                } else {
                    break;
                }
            }
            if (!prefix) { return ans; }
        }

        return ans + 1;
    }
};
// @lc code=end

