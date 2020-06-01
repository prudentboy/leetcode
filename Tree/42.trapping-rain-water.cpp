/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n(height.size());
        if (n < 3) { return 0; }

        int ans(0);
        int left(0), right(n - 1), tmp(0), small(0);
        while (left < right) {
            small = height[height[left] < height[right] ? left++ : right--];
            tmp = max(tmp, small);
            ans += tmp - small;
            if (height[left] < height[right]) {
                small = height[left++];
                while (left < right && height[left] <= small) {
                    ans += small - height[left++];
                }
            } else {
                small = height[right--];
                while (left < right && height[right] <= small) {
                    ans += small - height[right--];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

