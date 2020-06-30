/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : size_(12251), v_(12251, list<pair<int, int>>()) {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        if (v_[real_key].empty())
        {
            v_[real_key].push_back({key, value});
            return;
        }
        for (auto iter = v_[real_key].begin(); iter != v_[real_key].end(); ++iter)
        {
            if (iter->first == key)
            {
                iter->second = value;
                return;
            }
        }
        v_[real_key].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        if (v_[real_key].empty()) return -1;
        for (auto iter = v_[real_key].begin(); iter != v_[real_key].end(); ++iter)
        {
            if (iter->first == key) return iter->second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (get(key) == -1) return;
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        for (auto iter = v_[real_key].begin(); iter != v_[real_key].end(); ++iter)
        {
            if (iter->first == key)
            {
                v_[real_key].erase(iter);
                break;
            }
        }
    }
private:
    vector<list<pair<int, int>>> v_;
    int size_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

