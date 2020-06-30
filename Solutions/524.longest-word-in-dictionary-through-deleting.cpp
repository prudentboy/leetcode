/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxLen(0);
        string ans;
        vector<int> cnts(26, 0);
        for (char c : s) ++cnts[c - 'a'];
        for (const string& ds : d)
        {
            if (ds.size() > s.size() || ds.size() < maxLen) continue;
            if (!checkFunc(cnts, s, ds)) continue;
            if (ds.size() == maxLen && ds < ans) ans.assign(ds);
            else if (ds.size() > maxLen)
            {
                maxLen = ds.size();
                ans.assign(ds);
            }
        }
        return ans;
    }
private:
    bool checkFunc(vector<int> cnts, const string& os, const string& ds)
    {
        for (char c : ds) if (--cnts[c - 'a'] < 0) return false;
        int i(0), j(0);
        while (i < os.size() && j < ds.size())
        {
            while (i < os.size() && os[i] != ds[j]) ++i;
            if (i == os.size()) return false;
            ++i;
            ++j;
        }

        return j == ds.size();
    }
};
// @lc code=end

