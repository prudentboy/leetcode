/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
public:
    int flipLights(int n, int m) {
        string status(n, 'o');
        unordered_set<string> s;
        unordered_set<string> rec;
        updateSets(status, m, s, rec);
        return s.size();
    }
private:
    void updateSets(const string& status, int m, unordered_set<string>& s, unordered_set<string>& r)
    {
        string key(status);
        key += to_string(m);
        //cout << key << endl;
        if (r.count(key) > 0) return;
        if (m == 0)
        {
            s.insert(status);
            r.insert(key);
            return;
        }
        int i(0);
        string str(status);
        for (i = 0; i < str.size(); ++i) str[i] = str[i] == 'o' ? 'x' : 'o'; 
        updateSets(str, m - 1, s, r);
        str.assign(status);
        for (i = 0; i < str.size(); i += 2) str[i] = str[i] == 'o' ? 'x' : 'o';
        updateSets(str, m - 1, s, r);
        str.assign(status);
        for (i = 1; i < str.size(); i += 2) str[i] = str[i] == 'o' ? 'x' : 'o';
        updateSets(str, m - 1, s, r);
        str.assign(status);
        for (i = 0; i < str.size(); i += 3) str[i] = str[i] == 'o' ? 'x' : 'o';
        updateSets(str, m - 1, s, r);
        r.insert(key);
    }
};
// @lc code=end

