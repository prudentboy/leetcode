/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int i(0);
        unordered_map<char, char> w2p, p2w;
        for (string& word : words) {
            w2p.clear();
            p2w.clear();
            for (i = 0; i < word.size(); ++i) {
                if (w2p.count(word[i]) > 0 && w2p[word[i]] != pattern[i]) break;
                w2p[word[i]] = pattern[i];
                if (p2w.count(pattern[i]) > 0 && p2w[pattern[i]] != word[i]) break;
                p2w[pattern[i]] = word[i];
            }
            if (i == word.size()) ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end

