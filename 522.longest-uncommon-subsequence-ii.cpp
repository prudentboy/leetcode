/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        int ans(-1);
        int i(0), j(0), n(strs.size());
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (i == j) continue;
                if (checker(strs[i], strs[j])) break;
            }
            //cout << j << endl;
            if (j == n && (int)strs[i].size() > ans) ans = strs[i].size();
        }

        return ans;
    }
private:
    bool checker(const string& sub, const string& base)
    {
        if (sub.empty()) return true;
        if (sub.size() > base.size()) return false;

        int i(0);
        for (char c : base)
        {
            if (c == sub[i]) ++i;
            if (i == sub.size()) return true;
        }
        return false; 
    }
};
// @lc code=end

