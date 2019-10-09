/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        if (words.size() < 2) return ans;
        
        unordered_map<string, int> m;
        for (int i(0); i < words.size(); ++i) m[words[i]] = i;
        
        int l(0), r(0);
        string toFind, toCheck;
        vector<int> tmp(2, 0);
        for (int i(0); i < words.size(); ++i)
        {
            const string& w = words[i];
            l = 0;
            r = 0;
            while (l <= r)
            {
                toFind.assign(w.substr(l, r - l));
                reverse(toFind.begin(), toFind.end());
                if (l == 0) toCheck.assign(w.substr(r));
                else toCheck.assign(w.substr(0, l));
                //cout << toCheck << ' ' << toFind << endl;
                
                if (m.count(toFind) > 0 && m[toFind] != i && isPalindrome(toCheck))
                {
                    if (l != 0)
                    {
                        tmp[0] = m[toFind];
                        tmp[1] = i;
                    }
                    else
                    {
                        tmp[0] = i;
                        tmp[1] = m[toFind];
                    }
                    
                    //cout << w << ' ' << tmp[0] << ' ' << tmp[1] << endl;
                    ans.push_back(tmp);
                }
                
                if (r < w.size()) ++r;
                else ++l;
            }
        }
        
        return ans;
    }
private:
    bool isPalindrome(const string& s)
    {
        if (s.size() < 2) return true;
        
        int l(0), r(s.size() - 1);
        
        while (l < r) if (s[l++] != s[r--]) return false;
        
        return true;
    }
};
// @lc code=end

