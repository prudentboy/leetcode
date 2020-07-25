/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
public:
    BrowserHistory(string homepage) : idx_(0), mx_(0), his_({homepage}) {}
    
    void visit(string url) {
        if (idx_ + 1 == his_.size()) { his_.push_back(""); }
        his_[++idx_].assign(url);
        mx_ = idx_;
    }
    
    string back(int steps) {
        idx_ = max(0, idx_ - steps);
        return his_[idx_];
    }
    
    string forward(int steps) {
        idx_ = min(mx_, idx_ + steps);
        return his_[idx_];
    }
private:
    int mx_;
    int idx_;
    vector<string> his_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

