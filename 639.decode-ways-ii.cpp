/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) { return 0; }
        
        long long int pPre(1), pre(prefixCnt(s[0])), ans(pre);

        for (int i(1); i < s.size(); ++i) {
            ans = pre * prefixCnt(s[i]) + pPre * prefixCnt(s[i - 1], s[i]);
            ans %= M;
            pPre = pre;
            pre = ans;
        }

        return ans;
    }
private:
    static const int M = 1000000007;

    int prefixCnt(char c) {
        if (c == '0') return 0;
        if (c == '*') return 9;
        return 1;
    }

    int prefixCnt(char a, char b) {
        if (a == '*' && b == '*') { return 15; }
        if (a == '*') { return b <= '6' ? 2 : 1; }
        if (b == '*') {
            if (a > '2' || a == '0') { return 0; }
            if (a == '1') { return 9; }
            return 6;
        }
        if (a > '2' || a == '0') { return 0; }
        if (a == '1' || b <= '6') { return 1; }
        return 0;
    }
};
// @lc code=end

