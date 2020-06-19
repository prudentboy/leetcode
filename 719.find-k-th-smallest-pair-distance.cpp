/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n(nums.size());
        int l(0), r(nums.back() - nums.front() + 1), mid(0);
        int i(0), j(0), cnt(0);
        while (l < r) {
            mid = l + ((r - l) >> 1);
            //cout << l << ' ' << mid << ' ' << r << endl;
            cnt = 0;
            j = 1;
            for (i = 0; i < n - 1; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) { ++j; }
                cnt += j - i - 1;
                if (cnt > k) { break; }
                //cout << i << ' ' << cnt << endl;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
// @lc code=end

