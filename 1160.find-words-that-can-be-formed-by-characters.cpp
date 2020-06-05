/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        char dict[26] = {0};
        for (char c : chars) { ++dict[c - 'a']; }
        
        char word[26] = {0};
        int i(0), ans(0);
        bool flag(false);
        for (const string& w : words) {
            for (char c : w) {
                ++word[c - 'a'];
            }
            flag = true;
            for (int i(0); i < 26; ++i) {
                if (word[i] > dict[i]) { flag = false; }
                word[i] = 0;
            }
            if (flag) { ans += w.size(); }
        }

        return ans;
    }
};
// @lc code=end

