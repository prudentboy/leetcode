/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m_[val].insert(v_.size());
        v_.push_back(val);
        return m_[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m_[val].empty()) return false;
        size_t index(*(m_[val].begin()));
        m_[val].erase(index);
        if (index != v_.size() - 1)
        {
            int num(v_.back());
            v_[index] = num;
            m_[num].erase(v_.size() - 1);
            m_[num].insert(index);
        }
        v_.pop_back();
        //cout << v_.size() << endl;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index(rand() % v_.size());
        return v_[index];
    }
private:
    vector<int> v_;
    unordered_map<int, unordered_set<size_t>> m_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

