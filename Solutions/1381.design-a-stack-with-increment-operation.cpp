/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
public:
    CustomStack(int maxSize) : idx_(0), stk_(maxSize) {}
    
    void push(int x) {
        if (idx_ == stk_.size()) { return; }
        stk_[idx_++] = x;
    }
    
    int pop() {
        if (idx_ == 0) { return -1; }
        return stk_[--idx_];
    }
    
    void increment(int k, int val) {
        for (int i(0); i < min(k, idx_); ++i) { stk_[i] += val; }
    }
private:
    vector<int> stk_;
    int idx_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

