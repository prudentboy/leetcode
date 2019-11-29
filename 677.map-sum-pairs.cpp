/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
class MapSum {
    struct TrieNode
    {
        TrieNode* children[26];
        int val;
        TrieNode() : val(0)
        {
            for (int i(0); i < 26; ++i) children[i] = nullptr;
        }
    };
public:
    /** Initialize your data structure here. */
    MapSum() : d_(new TrieNode()) {}
    
    void insert(string key, int val) {
        TrieNode* tmp(d_);
        for (char c : key)
        {
            if (tmp->children[c - 'a'] == nullptr) tmp->children[c - 'a'] = new TrieNode();
            tmp = tmp->children[c - 'a'];
        }
        tmp->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* tmp(d_);
        for (char c : prefix)
        {
            if (tmp->children[c - 'a'] == nullptr) return 0;
            tmp = tmp->children[c - 'a'];
        }
        return sumHelper(tmp);
    }
private:
    TrieNode* d_;
private:
    int sumHelper(TrieNode* node)
    {
        if (node == nullptr) return 0;
        int ans(node->val);
        for (int i(0); i < 26; ++i)
        {
            if (node->children[i] != nullptr) ans += sumHelper(node->children[i]);
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

