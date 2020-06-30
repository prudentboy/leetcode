/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {}
    
    int get(int key) {
        auto iter = map_.find(key);
        if (iter == map_.end()) return -1;
        list_.splice(list_.begin(), list_, iter->second);

        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = map_.find(key);
        if (iter != map_.end())
        {
            iter->second->second = value;
            list_.splice(list_.begin(), list_, iter->second);
        }
        else
        {
            pair<int, int> p(key, value);
            list_.push_front(p);
            map_[key] = list_.begin();
            if (list_.size() > cap_)
            {
                map_.erase(list_.rbegin()->first);
                list_.pop_back();
            }
        }
    }
private:
    int cap_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

