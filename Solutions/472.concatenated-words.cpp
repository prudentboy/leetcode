/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        //unordered_set<size_t> len_dict;
        //for (const string& word : words) len_dict.insert(word.size());

        vector<string> ans;
        for (const string& word : words) if (helper(dict, word, word)) ans.push_back(word);
        return ans;
    }
private:
    bool helper(const unordered_set<string>& dict, const string& ori, const string& s)
    {
        //if (s.empty()) return true;
        string tmp;
        for (int i(1); i < s.size(); ++i)
        {
            //if (len_dict.count(i) == 0) continue;
            tmp.assign(s.substr(0, i));
            if (dict.count(tmp) == 0) continue;
            if (tmp == ori) continue;
            if (helper(dict, ori, s.substr(i))) return true;
        }
        return s != ori && dict.count(s);
    }
};
// @lc code=end

