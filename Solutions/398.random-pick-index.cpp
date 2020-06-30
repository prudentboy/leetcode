/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) : v_(nums)
    {
        srand(time(nullptr));
    }
    
    int pick(int target)
    {
        int cnt(0), ans(0);
        for (int i(0); i < v_.size(); ++i)
        {
            if (v_[i] == target && rand() % (++cnt) == 0) ans = i;
        }
        return ans;
    }
private:
    vector<int> v_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

