/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n(nums.size());

        auto check = [&](const int tempt) -> bool {
            int sum(0);
            for (int num : nums) {
                sum += (num + tempt - 1) / tempt;
                if (sum > threshold) { return false; }
            }
            return sum <= threshold;
        };

        int mid(0), left(1), right(*max_element(nums.begin(), nums.end()));
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

