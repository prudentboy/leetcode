/*
 * @lc app=leetcode id=822 lang=cpp
 *
 * [822] Card Flipping Game
 */

// @lc code=start
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans(INT_MAX);
        bool found(false);
        int i(0), n(fronts.size());
        unordered_set<int> s;
        for (i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) s.insert(fronts[i]);
        }
        for (i = 0; i < n; ++i) {
            if (s.count(fronts[i]) == 0 && fronts[i] < ans) {
                ans = fronts[i];
                found = true;
            }
            if (s.count(backs[i]) == 0 && backs[i] < ans) {
                ans = backs[i];
                found = true;
            }
        }
        return found ? ans : 0;
    }
};
// @lc code=end

