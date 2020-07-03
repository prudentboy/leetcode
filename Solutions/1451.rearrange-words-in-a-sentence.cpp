/*
 * @lc app=leetcode id=1451 lang=cpp
 *
 * [1451] Rearrange Words in a Sentence
 */

// @lc code=start
class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss(text);
        
        vector<string> words;
        string tmp, ans;
        while (ss >> tmp) { words.push_back(tmp); }
        
        stable_sort(words.begin(), words.end(), [](const string& l, const string& r) {
            return l.size() < r.size();
        });

        for (string& word : words) {
            if (ans.empty()) {
                word[0] &= '_';
                ans.assign(word);
            } else {
                word[0] |= ' ';
                ans += ' ';
                ans.append(word);
            }
        }

        return ans; 
    }
};
// @lc code=end

