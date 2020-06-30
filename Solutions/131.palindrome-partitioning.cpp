/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        return partition(s, 0);
    }
private:
    vector<vector<string>> partition(const string& s, int index)
    {
        vector<vector<string>> ans;

        if (s.empty() or index >= s.size()) return ans;
        if (index + 1 == s.size())
        {
            vector<string> tmp(1, s.substr(index));
            ans.push_back(tmp);
            return ans;
        }

        for (int i(index); i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                //cout << s.substr(index, i - index + 1) << endl;
                for (const auto& vec : partition(s, i + 1))
                {
                    vector<string> tmp;
                    tmp.push_back(s.substr(index, i - index + 1));
                    for (const string& str : vec) tmp.push_back(str);
                    ans.push_back(tmp);
                }
            }
        }

        if (isPalindrome(s, index, s.size() - 1))
        {
            vector<string> tmp(1, s.substr(index));
            ans.push_back(tmp);         
        }

        return ans;
    }
    bool isPalindrome(const string& s, int left, int right)
    {
        if (s.empty() || right >= s.size() || left < 0 || left > right) return false;

        while (left < right)
        {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

