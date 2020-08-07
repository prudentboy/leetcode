/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto start = lower_bound(ranges_.begin(), ranges_.end(), make_pair(left, right));
        if (start != ranges_.begin() && prev(start)->second >= left) { start = prev(start); }

        bool need_insert(true);
        while (start != ranges_.end()) {
            if (start->first > right) { break; }
            if (start->second >= right) {
                need_insert = false;
                break;
            }
            left = min(left, start->first);
            right = max(right, start->second);
            ranges_.erase(start);
        }
        if (need_insert) { ranges_.insert(make_pair(left, right)); }
        //printRange();
    }
    
    bool queryRange(int left, int right) {
        auto start = lower_bound(ranges_.begin(), ranges_.end(), make_pair(left, right));
        if (start != ranges_.begin() && prev(start)->second >= left) { start = prev(start); }
        return start->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto start = lower_bound(ranges_.begin(), ranges_.end(), make_pair(left, right));
        if (start != ranges_.begin() && prev(start)->second >= left) { start = prev(start); }

        int left1(-1), left2(-1), right1(-1), right2(-1);
        while (start != ranges_.end()) {
            if (start->first > right) { break; }
            if (start->second >= right) {
                if (start->first < left) {
                    left1 = start->first;
                    right1 = left;
                }
                if (start->second > right) {
                    left2 = right;
                    right2 = start->second;
                }
                ranges_.erase(start);
                break;
            }
            left1 = start->first;
            right1 = left;
            ranges_.erase(start);
        }
        if (left1 != -1) { ranges_.insert(make_pair(left1, right1)); }
        if (left2 != -1) { ranges_.insert(make_pair(left2, right2)); }
        //printRange();
    }
private:
    void printRange() {
        for (auto& p : ranges_) { cout << p.first << '-' << p.second << ' '; }
        cout << endl;
    }
private:
    set<pair<int, int>> ranges_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

