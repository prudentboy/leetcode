/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> ump;
        for (int n : target) { ++ump[n]; }
        for (int n : arr) { --ump[n]; }
        for (auto& p : ump) {
            if (p.second != 0) { return false; }
        }
        return true;
    }
};
// @lc code=end

