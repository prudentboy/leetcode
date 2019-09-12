/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> flags(s.size(), false);
        return wordBreak(s, dict, flags, 0);
    }
private:
    bool wordBreak(const string& s, const unordered_set<string>& dict, vector<bool>& flags, int index)
    {
        if (index >= s.size()) return true;
        if (flags[index]) return false;

        int j(index);
        string tmp;
        tmp.reserve(s.size());
        
        while (j < s.size())
        {
            tmp += s[j++];
            if (dict.count(tmp) > 0 && wordBreak(s, dict, flags, j))
            {
                return true;
            }
        }

        flags[index] = true;
        return false;
    }
};

