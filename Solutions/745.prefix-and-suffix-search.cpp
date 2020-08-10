/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i(0); i < words.size(); ++i) {
            string_view w(words[i]);
            for (int j(0); j <= w.size(); ++j) {
                for (int k(0); k <= w.size(); ++k) {
                    idx_dict_[move(getKey(w.substr(0, j), w.substr(k)))] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key(move(getKey(prefix, suffix)));
        if (idx_dict_.count(key) == 0) { return -1; }
        return idx_dict_[key];
    }

private:
    string getKey(string_view prefix, string_view suffix) {
        string pre(prefix), suf(suffix);
        pre += '|';
        pre += suf;
        return pre;
    }

private:
    unordered_map<string, int> idx_dict_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

