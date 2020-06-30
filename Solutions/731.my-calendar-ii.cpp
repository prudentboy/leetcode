/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        ++m_[start];
        --m_[end];
        int cnt(0);
        for (auto const& p : m_)
        {
            cnt += p.second;
            if (cnt >= 3)
            {
                --m_[start];
                ++m_[end];
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> m_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

