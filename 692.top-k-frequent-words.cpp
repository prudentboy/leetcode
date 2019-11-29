/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int mx(0);
        unordered_map<string, int> m;
        for (const string& w : words)
        {
            ++m[w];
            if (m[w] > mx) mx = m[w];
        }
        //cout << mx << endl;
        vector<set<string>> v(mx);
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            //cout << it->first << ' ' << it->second << endl;
            v[it->second - 1].insert(it->first);
        }
        vector<string> ans;
        for (int i(v.size() - 1); i >= 0; --i)
        {
            for (const string& s : v[i])
            {
                ans.push_back(s);
                if (--k == 0) return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

