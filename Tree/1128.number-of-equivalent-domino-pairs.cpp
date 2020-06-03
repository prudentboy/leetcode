/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int i(0), tmp(0);
        for (i = 0; i < dominoes.size(); ++i) {
            tmp = dominoes[i][0];
            if (dominoes[i][1] > tmp) {
                tmp = tmp * 10 + dominoes[i][1];
            } else {
                tmp = dominoes[i][1] * 10 + tmp; 
            }
            ++mp[tmp];
        }

        int ans(0);
        for (auto& p : mp) {
            ans += long(p.second * (p.second - 1)) / 2;
        }
        return ans;
    }
};
// @lc code=end

