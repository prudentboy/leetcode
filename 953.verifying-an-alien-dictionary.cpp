/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2) return true;

        int i(0);
        unordered_map<char, int> m;
        for (i = 0; i < order.size(); ++i) m[order[i]] = i;

        for (i = 1; i < words.size(); ++i)
        {
            if (!cmpAlien(words[i - 1], words[i], m)) return false;
        }
        return true;
    }
private:
    bool cmpAlien(const string& l, const string& r, unordered_map<char, int>& m)
    {
        int i(0);
        while (i < l.size() && i < r.size())
        {
            //cout << l[i] << ' ' << m[l[i]] << ' ' << r[i] << ' ' << m[r[i]] << endl;
            if (m[l[i]] > m[r[i]]) return false;
            else if (m[l[i]] < m[r[i]]) return true;
            ++i;
        }
        if (i < l.size()) return false;
        return true;
    } 
};

