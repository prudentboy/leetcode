/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

// @lc code=start
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cap(k);

        int i(0), n(nums.size());
        while (i < n && nums[i] == 0) { ++i; }

        for (; i < n; ++i) {
            //cout << i << ' ' << cap << endl;
            if (nums[i] == 0) {
                ++cap;
            } else {
                if (cap < k) { return false; }
                cap = 0;
            }
        }
        return true;
    }
};
// @lc code=end

