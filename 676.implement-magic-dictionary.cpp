/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

// @lc code=start
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (const string& s : dict) m_[s.size()].push_back(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        if (m_.count(word.size()) == 0) return false;
        for (const string& s : m_[word.size()])
        {
            if (check(s, word)) return true;
        }
        return false;
    }
private:
    bool check(const string& a, const string& b)
    {
        int cnt(0);
        for (int i(0); i < a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                ++cnt;
                if (cnt > 1) return false;
            }
        }
        return cnt == 1;
    }
private:
    unordered_map<int, vector<string>> m_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

