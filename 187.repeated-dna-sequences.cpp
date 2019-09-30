/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 11) return ans;

        unordered_set<string> s_set;

        for (int i(0); i + 9 < s.size(); ++i)
        {
            if (s_set.count(s.substr(i, 10)) > 0 and find(ans.begin(), ans.end(), s.substr(i, 10)) == ans.end()) ans.push_back(s.substr(i, 10));
            s_set.insert(s.substr(i, 10));
        }

        return ans;
    }
};

