/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.empty()) return "";

        unordered_set<string> dict(words.begin(), words.end());
        string ans;
        for (const string& s : words)
        {
            if (s.size() < ans.size()) continue;
            if (!fitDemand(s, dict)) continue;
            if (s.size() == ans.size())
            {
                if (s < ans) ans.assign(s);
            }
            else ans.assign(s);
            //cout << s << ' ' << ans << endl;
        }
        return ans;
    }
private:
    bool fitDemand(const string& s, const unordered_set<string>& dict)
    {
        if (s.empty()) return false;
        if (s.size() == 1 && dict.count(s) > 0) return true;

        string tmp;
        for (int i(0); i < s.size(); ++i)
        {
            tmp += s[i];
            if (dict.count(tmp) == 0) return false;
        }
        return true;
    }
};
// @lc code=end

