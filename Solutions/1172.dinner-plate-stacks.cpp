/*
 * @lc app=leetcode id=1172 lang=cpp
 *
 * [1172] Dinner Plate Stacks
 */

// @lc code=start
class DinnerPlates {
public:
    DinnerPlates(int capacity) : cap_(capacity) {}
    
    void push(int val) {
        int idx(-1);
        if (availables_.empty()) {
            idx = stacks_.size();
            stacks_.emplace_back();
        } else {
            idx = *availables_.begin();
        }

        stacks_[idx].push(val);
        if (stacks_[idx].size() == cap_) {
            availables_.erase(idx);
        } else if (stacks_[idx].size() == 1) {
            availables_.insert(idx);
        }
    }
    
    int pop() { return popAtStack(stacks_.size() - 1); }
    
    int popAtStack(int index) {
        if (index < 0 || index >= stacks_.size() || stacks_[index].empty()) { return -1; }
        int ret(stacks_[index].top());
        stacks_[index].pop();
        availables_.insert(index);
        if (index == stacks_.size() - 1 && stacks_[index].empty()) {
            auto back(availables_.end());
            while (index >= 0 && stacks_[index--].empty()) {
                stacks_.pop_back();
                availables_.erase(--back);
            }
        }
        return ret;
    }
private:
    int cap_;
    set<int> availables_;
    vector<stack<int>> stacks_;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

