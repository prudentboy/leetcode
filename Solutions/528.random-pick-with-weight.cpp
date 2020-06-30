/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& w) : sums_(w)
    {
        for (int i(1); i < sums_.size(); ++i) sums_[i] += sums_[i - 1];
        srand(time(nullptr));
    }
    
    int pickIndex()
    {
        int r(rand() % sums_.back());
        return upper_bound(sums_.begin(), sums_.end(), r) - sums_.begin();
    }
private:
    vector<int> sums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

