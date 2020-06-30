/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 */

// @lc code=start
class Solution {
public:
    Solution(int n_rows, int n_cols) : col_(n_cols), row_(n_rows), size_(n_cols * n_rows)
    {
        srand(time(nullptr));
    }
    
    vector<int> flip() {
        int index = rand() % size_;
        int val(index);
        --size_;
        if (m_.count(index)) index = m_[index];
        if (val != size_) m_[val] = m_.count(size_) ? m_[size_] : size_;
        return {index / col_, index % col_};
    }
    
    void reset() {
        m_.clear();
        size_ = col_ * row_;
    }
private:
    int col_, row_, size_;
    unordered_map<int, int> m_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end

