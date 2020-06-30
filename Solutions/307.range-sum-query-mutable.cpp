/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
class NumArray {
public:
    NumArray(vector<int>& nums) : _nums(nums) {}
    
    void update(int i, int val) {
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int ans(0);
        for (int k(i); k <= j; ++k)
        {
            ans += _nums[k];
        }
        return ans;
    }
private:
    vector<int> _nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

