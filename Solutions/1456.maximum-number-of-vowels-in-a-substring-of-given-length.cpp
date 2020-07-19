/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans(0);
        int i(0), j(0), cnt(0);
        for (i = 0; i < s.size(); ++i) {
            cnt += isVowel(s[i]);
            if (i - j + 1 > k) { cnt -= isVowel(s[j++]); }
            ans = max(ans, cnt);
        }
        return ans;
    }
private:
    int isVowel(char c) {
        switch (c) {
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                return 1;
            default :
                return 0;
        }
    }
};
// @lc code=end

