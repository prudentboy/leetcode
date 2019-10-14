/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab, cd;
        getTwoSumMap(A, B, ab);
        getTwoSumMap(C, D, cd);

        int ans(0);
        for (const auto& mnode : ab)
        {
            if (cd.count(-(mnode.first)) > 0) ans += mnode.second * cd[-(mnode.first)];
        }

        return ans;
    }
private:
    void getTwoSumMap(const vector<int>& x, const vector<int>& y, unordered_map<int, int>& m)
    {
        int i(0), j(0);
        for (i = 0; i < x.size(); ++i)
        {
            for (j = 0; j < y.size(); ++j)
            {
                if (m.count(x[i] + y[j]) > 0) ++m[x[i] + y[j]];
                else m[x[i] + y[j]] = 1;
            }
        }
    }
};
// @lc code=end

