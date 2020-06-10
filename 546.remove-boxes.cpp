/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
class Solution {
    using vec3d = vector<vector<vector<int>>>;
public:
    int removeBoxes(vector<int>& boxes) {
        const int n(boxes.size());
        vec3d dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return dfs(dp, boxes, 0, n - 1, 0);
    }
private:
    int dfs(vec3d& dp, const vector<int>& boxes, int left, int right, int k) {
        if (left > right) { return 0; }
        if (dp[left][right][k] > 0) { return dp[left][right][k]; }
        dp[left][right][k] = dfs(dp, boxes, left, right - 1, 0) + (k + 1) * (k + 1);
        for (int i(left); i < right; ++i) {
            if (boxes[i] == boxes[right]) {
                dp[left][right][k] = max(dp[left][right][k], \
                                         dfs(dp, boxes, left, i, k + 1) + dfs(dp, boxes, i + 1, right - 1, 0));
            }
        }
        return dp[left][right][k];
    }
};
// @lc code=end

