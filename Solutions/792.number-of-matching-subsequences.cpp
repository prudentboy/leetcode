/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int>> m;
        for (int i(0); i < S.size(); ++i) m[S[i]].push_back(i);
        int ans(0);
        for (const string& word : words) {
            if (checkMatch(word, m)) ++ans;
        }
        return ans;
    }
private:
    bool checkMatch(const string& s, unordered_map<char, vector<int>>& m) {
        vector<int> idx(26, 0);
        int pre(-1);
        for (char c : s) {
            if (idx[c - 'a'] >= m[c].size()) return false;
            while (idx[c - 'a'] < m[c].size() && m[c][idx[c - 'a']] <= pre) {
                ++idx[c - 'a'];
            }
            if (idx[c - 'a'] >= m[c].size()) return false;
            pre = m[c][idx[c - 'a']];
            ++idx[c - 'a'];
        }
        return true;
    }
};
// @lc code=end

