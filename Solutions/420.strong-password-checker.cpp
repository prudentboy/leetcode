/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string s) {
        int ans(0);
        
        int n(s.size());
        int i(0), j(0);
        int lower(1), upper(1), digit(1);
        vector<int> rep(n, 0);
        for (i = 0; i < n;)
        {
            if (s[i] >= 'a' && s[i] <= 'z') lower = 0;
            else if (s[i] >= 'A' && s[i] <= 'Z') upper = 0;
            else if (s[i] >= '0' && s[i] <= '9') digit = 0;
            j = i;
            while (i < n && s[i] == s[j]) ++i;
            rep[j] = i - j;
        }
        int typeCnt = lower + upper + digit;
        if (n < 6) return max(6 - n, typeCnt);
        int lenCnt(max(0, n - 20));
        ans += lenCnt;
        int repCnt(0);
        for (i = 0; i < n && lenCnt > 0; ++i)
        {
            if (rep[i] > 2)
            {
                if (rep[i] % 3 == 0)
                {
                    --lenCnt;
                    --rep[i];
                }
                else if (rep[i] % 3 == 1 && lenCnt > 1)
                {
                    lenCnt -= 2;
                    rep[i] -= 2;
                }
            }
        }
        int need(0);
        for (i = 0; i < n; ++i)
        {
            if (rep[i] > 2)
            {
                if (lenCnt > 0)
                {
                    need = rep[i] - 2;
                    rep[i] -= (lenCnt > need ? need : lenCnt);
                    lenCnt -= need;
                }
                repCnt += rep[i] / 3;
            }
        }
        //cout << typeCnt << ' ' << repCnt << endl;
        ans += max(typeCnt, repCnt);
        return ans;
    }
};
// @lc code=end

