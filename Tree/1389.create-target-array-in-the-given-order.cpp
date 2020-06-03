/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 */

// @lc code=start
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n(nums.size());
        vector<int> ans(n, -1);

        int i(0), j(0), cnt(0);
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (index[j] <= index[i]) { ++index[i]; }
            }
            //cout << index[i] << ' ' << nums[i] << endl;
            ans[index[i]] = nums[i];
        }
        return ans;
    }
};
// @lc code=end

