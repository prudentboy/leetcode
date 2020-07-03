/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ust;
        string ans;
        for (auto& path : paths) { ust.insert(path[0]); }
        for (auto& path : paths) {
            if (ust.count(path[1]) == 0) {
                ans.assign(path[1]);
            }
        }
        return ans;
    }
};
// @lc code=end

