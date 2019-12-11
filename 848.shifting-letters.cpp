/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum(0), i(0), n(shifts.size());
        for (i = n - 1; i >= 0; --i) {
            sum += shifts[i];
            sum %= 26;
            shifts[i] = sum;
        }
        int tmp(0);
        for (i = 0; i < n; ++i) {
            tmp = S[i] + shifts[i];
            if (tmp > int('z')) tmp -= 26;
            S[i] = char(tmp);
            //cout << S[i] << ' ' << int(S[i]) << endl;
        }
        return S;
    }
};
// @lc code=end

