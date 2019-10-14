/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// @lc code=start
class Solution {
public:
    Solution(vector<vector<int>>& rects) : size_(0), rects_(rects)
    {
        srand(time(nullptr));
        for (int i(0); i < rects_.size(); ++i)
        {
            size_ += (rects_[i][2] - rects_[i][0] + 1) * (rects_[i][3] - rects_[i][1] + 1);
            m_[size_] = i;
        }
    }
    
    vector<int> pick() {
        int index(m_.upper_bound(rand() % size_)->second);
        int x(rand() % (rects_[index][2] - rects_[index][0] + 1) + rects_[index][0]);
        int y(rand() % (rects_[index][3] - rects_[index][1] + 1) + rects_[index][1]);
        return {x, y};
    }
private:
    int size_;
    vector<vector<int>> rects_;
    map<int, int> m_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

