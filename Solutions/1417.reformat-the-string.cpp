/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        int dgtCnt(0), lttrCnt(0);
        for (char c : s) {
            if (isdigit(c)) {
                ++dgtCnt;
            } else {
                ++lttrCnt;
            }
        }

        if (abs(dgtCnt - lttrCnt) > 1) { return ""; }

        string ans;
        int i(0), j(0);
        while (dgtCnt + lttrCnt > 0) {
            if (dgtCnt > lttrCnt || (!ans.empty() && !isdigit(ans.back()))) {
                while (!isdigit(s[i])) { ++i; }
                ans += s[i++];
                --dgtCnt;
            } else {
                while (isdigit(s[j])) { ++j; }
                ans += s[j++];
                --lttrCnt;
            }
            //cout << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

