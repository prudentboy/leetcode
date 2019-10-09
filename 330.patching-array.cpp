/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int i(0), ans(0), miss(1);
        
        while (miss <= n)
        {
            if (i < nums.size() && miss >= nums[i]) miss += nums[i++];
            else
            {
                miss <<= 1;
                ++ans;
            }
            //cout << i << ' ' << miss << ' ' << ans << endl;
        }
        
        return ans;
    }
};
// @lc code=end

