/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> table;
        return wordBreak(s, 0, dict, table);
    }
private:
    vector<string> wordBreak(const string& s, int index, const unordered_set<string>& dict, unordered_map<int, vector<string>>& table)
    {
        if (table.find(index) != table.end()) return table[index];
        if (index >= s.size()) return {""};

        vector<string> res;
        string word, tmp;
        word.reserve(s.size());
        int i(index);

        while (i < s.size())
        {
            word += s[i++];
            if (dict.count(word) > 0)
            {
                for (const auto& str : wordBreak(s, i, dict, table))
                {
                    tmp = word;
                    if (!str.empty()) tmp.append(" ").append(str);
                    res.push_back(tmp);
                }
            }
        }
        table[index] = res;

        return res;
    }
};

