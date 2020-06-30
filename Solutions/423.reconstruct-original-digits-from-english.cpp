/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        int alpha[26] = {0};
        int digit[10] = {0};

        for (char c : s) ++alpha[c - 'a'];
        //for (char c('a'); c <= 'z'; ++c) cout << c << ':' << alpha[c - 'a'] << endl; 

        while (alpha['z' - 'a'] > 0)
        {
            ++digit[0];
            --alpha['z' - 'a'];
            --alpha['e' - 'a'];
            --alpha['r' - 'a'];
            --alpha['o' - 'a'];
        }
        while (alpha['w' - 'a'] > 0)
        {
            ++digit[2];
            --alpha['t' - 'a'];
            --alpha['w' - 'a'];
            --alpha['o' - 'a'];
        }
        while (alpha['x' - 'a'] > 0)
        {
            ++digit[6];
            --alpha['s' - 'a'];
            --alpha['x' - 'a'];
            --alpha['i' - 'a'];
        }
        while (alpha['g' - 'a'] > 0)
        {
            ++digit[8];
            --alpha['e' - 'a'];
            --alpha['i' - 'a'];
            --alpha['g' - 'a'];
            --alpha['h' - 'a'];
            --alpha['t' - 'a'];
        }
        while (alpha['h' - 'a'] > 0)
        {
            ++digit[3];
            --alpha['t' - 'a'];
            --alpha['h' - 'a'];
            --alpha['r' - 'a'];
            alpha['e' - 'a'] -= 2;
        }
        while (alpha['r' - 'a'] > 0)
        {
            ++digit[4];
            --alpha['f' - 'a'];
            --alpha['o' - 'a'];
            --alpha['u' - 'a'];
            --alpha['r' - 'a'];
        }
        while (alpha['f' - 'a'] > 0)
        {
            ++digit[5];
            --alpha['f' - 'a'];
            --alpha['i' - 'a'];
            --alpha['v' - 'a'];
            --alpha['e' - 'a'];
        }
        while (alpha['v' - 'a'] > 0)
        {
            ++digit[7];
            --alpha['s' - 'a'];
            alpha['e' - 'a'] -= 2;
            --alpha['v' - 'a'];
            --alpha['n' - 'a'];
        }
        while (alpha['o' - 'a'] > 0)
        {
            ++digit[1];
            --alpha['o' - 'a'];
            --alpha['n' - 'a'];
            --alpha['e' - 'a'];
        }
        while (alpha['i' - 'a'] > 0)
        {
            ++digit[9];
            alpha['n' - 'a'] -= 2;
            --alpha['e' - 'a'];
            --alpha['i' - 'a'];
        }

        string ans;
        for (int i(0); i < 10; ++i)
        {
            //cout << i << ':' << digit[i] << endl;
            while (digit[i]-- > 0) ans += (i + '0');
        }

        return ans;
    }
};
// @lc code=end

