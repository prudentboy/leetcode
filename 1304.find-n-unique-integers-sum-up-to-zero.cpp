/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        ans.reserve(n);

        int cnt(n >> 1);
        if ((n & 1) == 1) {
            ans.push_back(0);
        }
        for (int i(1); i <= cnt; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};
// @lc code=end

