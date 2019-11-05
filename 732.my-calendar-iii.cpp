/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++m_[start];
        --m_[end];
        int cnt(0), ans(0);
        for (const auto& p : m_)
        {
            cnt += p.second;
            ans = max(ans, cnt);
        }
        return ans;
    }

private:
    map<int, int> m_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

