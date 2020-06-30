/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */
class Solution {
public:
    int countSubstrings(string s) {
        int ans(0);
        if (s.empty()) return ans;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i(0); i < s.size(); ++i)
        {
            for (int j(0); j <= i; ++j)
            {
                if (s[i] == s[j] && (i - j <= 2 || dp[i - 1][j + 1])) dp[i][j] = true;
                if (dp[i][j]) ++ans;
            }
            //printDP(dp);
        }
        return ans;
    }
private:
    void printDP(const vector<vector<bool>>& dp)
    {
        for (int i(0); i < dp.size(); ++i)
        {
            for (int j(0); j < dp[0].size(); ++j)
            {
                if (dp[i][j]) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
};

