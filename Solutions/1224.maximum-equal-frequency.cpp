/*
 * @lc app=leetcode id=1224 lang=cpp
 *
 * [1224] Maximum Equal Frequency
 */

// @lc code=start
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int mx(0);
        unordered_map<int, int> cnts, freqs;
        cnts[0] = 1;

        auto check = [&]() -> bool {
            if (freqs.empty() || freqs.size() > 2) { return false; }
            if (freqs.size() == 1) { return freqs.count(1) > 0; }
            if (freqs.count(1) > 0 && freqs[1] == 1) { return true; }
            int mn(INT_MAX), mx(INT_MIN);
            for (auto& p : freqs) {
                mn = min(mn, p.first);
                mx = max(mx, p.first);
            }
            return mx == mn + 1 && freqs[mx] == 1;
        };

        int ans(0);
        bool isAllSame(true);
        for (int i(0); i < nums.size(); ++i) {
            if (nums[i] != nums.front()) { isAllSame = false; }
            if (--freqs[cnts[nums[i]]] <= 0) { freqs.erase(cnts[nums[i]]); }
            ++freqs[++cnts[nums[i]]];
            if (isAllSame || check()) { ans = i + 1; }
        }
        return ans;
    }
};
// @lc code=end

