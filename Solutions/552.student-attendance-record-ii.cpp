/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) { return 3; }
        if (n == 2) { return 8; }
        if (n == 3) { return 19; }

        const int M = 1000000007;        
        int APPP(1), APP(2), AP(4);
        int PPP(3), PP(8), LP(7);
        int A(0), L(0), P(0);

        for (int i(3); i < n; ++i) {
            A = ((AP + APP) % M + APPP) % M;
            L = ((AP + PP) % M + (APP + PPP) % M) % M;
            P = ((AP + LP) % M + PP) % M;
            APPP = APP, APP = AP, AP = A;
            PPP = PP, PP = P;
            LP = L;
        }
        return ((A + L) % M + P) % M;
    }
};
// @lc code=end

