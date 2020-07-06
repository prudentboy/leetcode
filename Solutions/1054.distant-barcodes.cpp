/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n(barcodes.size());

        int mxNum(0), mxCnt(0);
        unordered_map<int, int> ump;
        for (int bar : barcodes) {
            if (++ump[bar] > mxCnt) {
                mxCnt = ump[bar];
                mxNum = bar;
            }
        }

        vector<int> ans(n);
        int idx(0);
        while (ump[mxNum]-- > 0) {
            ans[idx] = mxNum;
            idx += 2;
        }
        if (idx >= n) { idx = 1; }
        for (auto& p : ump) {
            int cnt(p.second);
            while (cnt-- > 0) {
                ans[idx] = p.first;
                idx += 2;
                if (idx >= n) { idx = 1; }
            }
        }

        return ans;
    }
};
// @lc code=end

