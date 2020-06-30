/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        dict_[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (dict_.count(key) == 0) { return ""; }
        auto iter = dict_[key].upper_bound(timestamp);
        if (iter == dict_[key].begin()) { return ""; }
        return prev(iter)->second;
    }

private:
    unordered_map<string, map<int, string>> dict_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

