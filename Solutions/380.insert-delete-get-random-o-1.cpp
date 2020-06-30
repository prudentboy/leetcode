/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m_.count(val) > 0) return false;
        v_.push_back(val);
        m_[val] = v_.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m_.count(val) == 0) return false;
        int back(v_.back());
        v_[m_[val]] = back;
        m_[back] = m_[val];
        m_.erase(val);
        v_.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        size_t index(rand() % v_.size());
        return v_[index];
    }
private:
    vector<int> v_;
    unordered_map<int, size_t> m_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

