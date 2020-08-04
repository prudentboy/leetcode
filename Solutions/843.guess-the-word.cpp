/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> range(wordlist);
        while (true) {
            string attempt(range[rand() % (range.size())]);
            int res(master.guess(attempt));
            if (res == 6) { return; }
            int idx(0);
            for (int i(0); i < range.size(); ++i) {
                if (matchCnt(range[i], attempt) == res) { range[idx++] = range[i]; }
            }
            range.resize(idx);
            //cout << idx << ' ' << range.size() << endl;
        }
    }
private:
    int matchCnt(string_view s1, string_view s2) {
        int ret(0);
        for (int i(0); i < s1.size(); ++i) {
            if (s1[i] == s2[i]) { ++ret; }
        }
        return ret;
    }
};
// @lc code=end

