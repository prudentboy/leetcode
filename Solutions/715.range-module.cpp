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
        map<int, int>::iterator l, r;
        getOverlapRanges(left, right, l, r);
        if (l != r) {
            auto last(r);
            --last;
            left = min(left, l->first);
            right = max(right, last->second);
            ranges_.erase(l, r);
        }
        ranges_[left] = right;
        //printRange();
    }
    
    bool queryRange(int left, int right) {
        map<int, int>::iterator l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) { return false; }
        return l->first <= left && l->second >= right;
    }
    
    void removeRange(int left, int right) {
        map<int, int>::iterator l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) { return; }
        auto last(r);
        --last;
        int beg(min(l->first, left)), end(max(last->second, right));
        ranges_.erase(l, r);
        if (beg < left) { ranges_[beg] = left; }
        if (end > right) { ranges_[right] = end; }
        //printRange();
    }
private:
    void printRange() {
        for (auto& p : ranges_) { cout << p.first << '-' << p.second << ' '; }
        cout << endl;
    }
    void getOverlapRanges(int left, int right, map<int, int>::iterator& l, map<int, int>::iterator& r) {
        l = ranges_.upper_bound(left);
        r = ranges_.upper_bound(right);
        if (l == ranges_.begin()) { return; }
        if ((--l)->second < left) { ++l; }
    }
private:
    map<int, int> ranges_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

