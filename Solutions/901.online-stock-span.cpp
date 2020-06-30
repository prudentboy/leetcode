/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        v_.clear();
        dp_.clear();
    }
    
    int next(int price) {
        v_.push_back(price);
        if (v_.size() == 1) {
            dp_.push_back(1);
            return 1;
        }
        int j = v_.size() - 2;
        while (j >= 0) {
            if (v_[j] > price) {
                dp_.push_back(v_.size() - j - 1);
                //cout << j << v_.back() << dp_.back() << endl;
                return v_.size() - j - 1;
            } else {
                j -= dp_[j];
            }
        }
        if (j < 0) {
            dp_.push_back(v_.size());
            return v_.size();
        }
        return v_.size() - j - 1;
    }
private:
    vector<int> v_;
    vector<int> dp_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

