/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : size_(12251), v_(12251, list<int>()) {}
    
    void add(int key) {
        if (contains(key)) return;
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        v_[real_key].push_back(key);
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        for (auto iter = v_[real_key].begin(); iter != v_[real_key].end(); ++iter)
        {
            if (*iter == key)
            {
                v_[real_key].erase(iter);
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int real_key = ((long long int)key * key * 7 >> 2) % size_;
        if (v_[real_key].empty()) return false;
        for (int n : v_[real_key])
        {
            if (n == key) return true;
        }
        return false;
    }
private:
    vector<list<int>> v_;
    int size_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

