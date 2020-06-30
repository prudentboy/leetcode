/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans(0);
        longestSubstring(s, k, ans);
        return ans;
    }
private:
    void longestSubstring(const string& s, int k, int& ans)
    {
        if (s.size() < k) return;
        
        bool flag(true);
        int m[26] = {0};
        
        for (char c : s) ++m[c - 'a'];
        for (int i(0); i < 26; ++i) if (m[i] > 0 && m[i] < k) flag = false;
        if (flag) ans = max(ans, (int)s.size());
        else
        {
            for (int i(0); i < s.size(); ++i)
            {
                if (m[s[i] - 'a'] > 0 && m[s[i] - 'a'] < k)
                {
                    longestSubstring(s.substr(0, i), k, ans);
                    longestSubstring(s.substr(i + 1), k, ans);
                    break;
                }
            }
        }
    }
};
// @lc code=end

