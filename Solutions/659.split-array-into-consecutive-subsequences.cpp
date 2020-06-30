/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, need;
        for (int n : nums) ++cnt[n];
        for (int n : nums)
        {
            if (cnt[n] == 0) continue;
            if (cnt[n] < 0) return false;
            if (need[n] > 0)
            {
                --need[n];
                ++need[n + 1];
            }
            else if (cnt[n + 1] > 0 && cnt[n + 2] > 0)
            {
                --cnt[n + 1];
                --cnt[n + 2];
                ++need[n + 3];
            }
            else return false;
            --cnt[n];
        }
        return true;
    }
};
// @lc code=end

