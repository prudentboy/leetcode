/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty()) return 0;

        int mx(-1), ans(0);
        for (int i(0); i < arr.size(); ++i)
        {
            mx = max(mx, arr[i]);
            if (mx == i) {
                ++ans;
                mx = -1;
            }
        }
        return ans;
    }
};
// @lc code=end

