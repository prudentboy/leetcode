/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) : v_(nums) {
        srand(time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(v_);

        for (int i(0); i < ans.size(); ++i)
        {
            swap(ans[i], ans[i + rand() % (ans.size() - i)]);
        }
        return ans;
    }
private:
    vector<int> v_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

