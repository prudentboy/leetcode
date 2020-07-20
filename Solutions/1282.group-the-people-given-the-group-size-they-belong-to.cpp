/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;

        int sz(0);
        unordered_map<int, vector<int>> ump;
        for (int i(0); i < groupSizes.size(); ++i) {
            sz = groupSizes[i];
            if (ump[sz].size() < sz) { ump[sz].push_back(i); }
            if (ump[sz].size() == sz) {
                ans.emplace_back(ump[sz]);
                ump[sz].clear();
            }
        }

        return ans;
    }
};
// @lc code=end

