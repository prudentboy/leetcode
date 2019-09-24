/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;

        vector<int> dp(s.size(), 0);
        vector<vector<bool>> dpP(s.size(), vector<bool>(s.size(), false));

        for (int i(0); i < dp.size(); ++i) dp[i] = i;

        for (int i(0); i < dpP.size(); ++i)
        {
            for (int j(0); j <= i; ++j)
            {
                if (s[i] == s[j] && (i - j <= 2 || dpP[i - 1][j + 1])) dpP[i][j] = true;
            }
        }
        //printDPP(dpP);

        for (int i(0); i < dp.size(); ++i)
        {
            //printDP(dp);
            if (dpP[i][0])
            {
                dp[i] = 0;
                continue;
            }
            for (int j(1); j <= i; ++j)
            {
                if (dpP[i][j] && dp[j - 1] + 1 < dp[i])
                {
                    dp[i] = dp[j - 1] + 1;
                }
            }
        }
        //printDP(dp);

        return dp.back();
    }
private:
    void printDP(const vector<int>& dp)
    {
        for (const auto& n : dp) cout << n << '-';
        cout << endl;
    }
    void printDPP(const vector<vector<bool>>& dp)
    {
        for (int i(0); i < dp.size(); ++i)
        {
            for (int j(0); j < dp[0].size(); ++j) cout << dp[i][j] << ' ';
            cout << endl;
        }
    }
};

