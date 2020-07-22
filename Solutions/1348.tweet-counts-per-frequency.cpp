/*
 * @lc app=leetcode id=1348 lang=cpp
 *
 * [1348] Tweet Counts Per Frequency
 */

// @lc code=start
class TweetCounts {
public:
    TweetCounts() : interval_({{"minute", 60}, {"hour", 3600}, {"day", 86400}}) {}
    
    void recordTweet(string tweetName, int time) {
        record_[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta(interval_[freq]);
        if (record_.count(tweetName) == 0) { return {}; }
        const auto& rec(record_[tweetName]);
        vector<int> ret;
        for (int i(startTime); i <= endTime; i += delta) {
            auto left = rec.lower_bound(i);
            auto right = rec.lower_bound(min(i + delta, endTime + 1));
            ret.push_back(distance(left, right));
        }
        return ret;
    }
private:
    unordered_map<string, set<int>> record_;
    unordered_map<string, int> interval_;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
// @lc code=end

