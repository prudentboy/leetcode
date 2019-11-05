/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto iter = timetable.lower_bound(start);
        if (iter != timetable.end() && end > iter->first) return false;
        if (iter != timetable.begin() && start < prev(iter)->second) return false;
        timetable[start] = end;
        return true;
    }
private:
    map<int, int> timetable;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

