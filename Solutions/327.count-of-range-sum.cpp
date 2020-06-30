/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans(0);
        long long int sum(0);
        multiset<long long int> s;
        s.insert(0);
        
        for (int n : nums)
        {
            sum += n;
            ans += distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }
        
        return ans;
    }
};
// @lc code=end

