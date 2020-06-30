/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

// @lc code=start
class RLEIterator {
public:
    RLEIterator(vector<int>& A) : idx_(0), v_(A) {}
    
    int next(int n) {
        while (idx_ < v_.size() && n > v_[idx_]) {
            n -= v_[idx_];
            idx_ += 2;
        }
        if (idx_ >= v_.size()) return -1;
        v_[idx_] -= n;
        return v_[idx_ + 1];
    }
private:
    size_t idx_;
    vector<int> v_;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
// @lc code=end

