/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int cnt(0);
        int i(0);
        while (ss >> word) {
            ++cnt;
            if (word.size() < searchWord.size()) { continue; }
            for (i = 0; i < searchWord.size(); ++i) {
                if (word[i] != searchWord[i]) { break; }
            }
            if (i == searchWord.size()) return cnt;
        }
        return -1;
    }
};
// @lc code=end

