/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans(A + B, ' ');

        int i(0);
        char more('a'), less('b');
        if (A < B) {
            more = 'b';
            less = 'a';
            swap(A, B);
        }
        
        while (A > 0 || B > 0) {
            if (A > 0) {
                ans[i++] = more;
                --A;
            }
            if (A > B) {
                ans[i++] = more;
                --A;
            }
            if (B > 0) {
                ans[i++] = less;
                --B;
            }
        }
        
        return ans;
    }
};
// @lc code=end

