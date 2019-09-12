/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> table(s.size(), false);
        string sentence;
        wordBreak(s, 0, dict, table, sentence, ans);
        return ans;
    }
private:
    bool wordBreak(const string& s, int index, const unordered_set<string>& dict, vector<bool>& table, string& sentence, vector<string>& ans)
    {
        if (index >= s.size())
        {
            sentence.pop_back();
            ans.push_back(sentence);
            sentence.clear();
            return true;
        }
        if (table[index]) return false;

        string tmp;
        tmp.reserve(s.size());
        int i(index);

        while (i < s.size())
        {
            tmp += s[i++];
            if (dict.count(tmp) > 0)
            {
                cout << tmp << '-' << sentence << endl;
                sentence.append(tmp).append(" ");
                wordBreak(s, i, dict, table, sentence, ans);
            }
        }

        table[index] = true;
        return false;
    }
};

