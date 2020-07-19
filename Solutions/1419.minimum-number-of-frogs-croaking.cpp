/*
 * @lc app=leetcode id=1419 lang=cpp
 *
 * [1419] Minimum Number of Frogs Croaking
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n(croakOfFrogs.size());
        if (n % 5 != 0) { return -1; }

        int ans(0);
        unordered_map<char, int> ump({{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}});
        vector<int> cur(5);

        int idx(0);
        for (char v : croakOfFrogs) {
            idx = ump[v];
            ++cur[idx];
            if (idx != 0 && cur[idx] > cur[idx - 1]) { return -1; }
            if (idx == 0) { ans = max(ans, cur.front()); }
            if (idx == 4) {
                --cur[0];
                --cur[1];
                --cur[2];
                --cur[3];
                --cur[4];
            }
        }

        if (cur[0] > 0) { return -1; }
        
        return ans;
    }
};
// @lc code=end

