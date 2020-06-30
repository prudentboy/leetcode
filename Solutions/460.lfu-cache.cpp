/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) : cap_(capacity), lf_(0) {}
    
    int get(int key) {
        //cout << "Get: " << key << ' ' << data_.count(key) << endl; 
        if (data_.count(key) == 0) return -1;
        //cout << data_[key].first << ' ' << data_[key].second << endl;
        freq_[data_[key].second].erase(iter_[key]);
        ++data_[key].second;
        freq_[data_[key].second].push_back(key);
        iter_[key] = --freq_[data_[key].second].end();
        //cout << data_[key].first << ' ' << data_[key].second << endl;
        if (freq_[lf_].empty()) ++lf_;
        //cout << "lf: " << lf_ << endl;
        return data_[key].first;
    }
    
    void put(int key, int value) {
        //cout << "Put: " << key << '-' << value << endl; 
        if (cap_ <= 0) return;
        if (get(key) != -1)
        {
            data_[key].first = value;
            return;
        }
        if (data_.size() >= cap_)
        {
            int k = freq_[lf_].front();
            data_.erase(k);
            iter_.erase(k);
            cout << k << ' ' << data_.count(k) << endl;
            freq_[lf_].pop_front();
        }
        data_[key] = make_pair(value, 1);
        lf_ = 1;
        freq_[lf_].push_back(key);
        iter_[key] = --freq_[lf_].end();
    }
private:
    int cap_;
    int lf_;
    unordered_map<int, pair<int, int>> data_;
    unordered_map<int, list<int>> freq_;
    unordered_map<int, list<int>::iterator> iter_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

