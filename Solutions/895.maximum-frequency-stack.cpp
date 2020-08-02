/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {}
    
    void push(int x) {
        if (cnts_[x] == stacks_.size()) { stacks_.push_back({}); }
        stacks_[cnts_[x]++].push(x);
    }
    
    int pop() {
        int ret(stacks_.back().top());
        stacks_.back().pop();
        if (stacks_.back().empty()) { stacks_.pop_back(); }
        --cnts_[ret];
        return ret;
    }
private:
    vector<stack<int>> stacks_;
    unordered_map<int, int> cnts_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
// @lc code=end

