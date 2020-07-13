/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        const vector<int> noRes(2, -1);
        
        int n(A.size());
        if (n < 3) { return noRes; }
        
        int cnt(0), k(0);
        for (k = 0; k < n; ++k) { cnt += A[k]; }
        
        if (cnt == 0) { return {0, n - 1}; }
        if (cnt % 3 != 0) { return noRes; }

        int num(0), i(0), j(0);
        for (j = n - 1; j >= 0; --j) {
            num += A[j];
            if (num * 3 == cnt) { break; }
        }

        i = 0;
        while (A[i] == 0) { ++i; }
        for (k = j; k < n; ++k) {
            if (A[i] != A[k]) { return noRes; }
            ++i;
        }

        vector<int> ans({i - 1, j});

        while (A[i] == 0) { ++i; }
        for (k = j; k < n; ++k) {
            if (A[i] != A[k]) { return noRes;}
            ++i;
        }
        ans[1] = i;

        return ans;
    }
};
// @lc code=end

