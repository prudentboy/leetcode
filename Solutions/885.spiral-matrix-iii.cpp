/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        int step(1);
        int i(0);
        while (ans.size() < R * C) {
            for (i = 0; i < step; ++i) {
                if (valid(R, C, r0, c0)) ans.push_back({r0, c0});
                ++c0;
            }
            for (i = 0; i < step; ++i) {
                if (valid(R, C, r0, c0)) ans.push_back({r0, c0});
                ++r0;
            }
            ++step;
            for (i = 0; i < step; ++i) {
                if (valid(R, C, r0, c0)) ans.push_back({r0, c0});
                --c0;
            }
            for (i = 0; i < step; ++i) {
                if (valid(R, C, r0, c0)) ans.push_back({r0, c0});
                --r0;
            }
            ++step;
        }
        return ans;
    }
private:
    inline bool valid(int R, int C, int x, int y) {
        return (x >= 0 && x < R && y >= 0 && y < C); 
    }
};
// @lc code=end

