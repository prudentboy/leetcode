/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        vector<int> interval({val, val});
        for (auto iter = intervals_.begin(); iter != intervals_.end(); ++iter)
        {
            if ((*iter)[0] > interval[1] + 1 || (*iter)[1] + 1 < interval[0]) continue;
            interval[0] = min(interval[0], (*iter)[0]);
            interval[1] = max(interval[1], (*iter)[1]);
            intervals_.erase(iter--);
        }
        intervals_.push_back(interval);
        sort(intervals_.begin(), intervals_.end());
    }
    
    vector<vector<int>> getIntervals() {
        return intervals_;
    }
private:
    vector<vector<int>> intervals_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

