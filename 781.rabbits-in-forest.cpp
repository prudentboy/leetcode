/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans(0);
        unordered_map<int, int> m;
        for (int n : answers) {
            ++m[n];
        }
        for (auto& p : m) {
            ans += (p.first + p.second) / (p.first + 1) * (p.first + 1);
        }
        return ans;
    }
};
// @lc code=end

