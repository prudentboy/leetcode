/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int i(0), n(dominoes.size()), now(0);
        for (i = 0; i < n; ++i) {
            switch (dominoes[i]) {
                case 'L' :
                    now = 0;
                    break;
                case 'R' :
                    now = 1;
                    break;
                case '.' :
                    if (now <= 0) continue;
                    dominoes[i] = now++; 
            }
        }
        //cout << dominoes << endl;
        now = 0;
        for (i = n - 1; i >= 0; --i) {
            switch (dominoes[i]) {
                case 'L' :
                    now = 1;
                    break;
                case 'R' :
                    now = 0;
                    break;
                case '.' :
                    if (now > 0) dominoes[i] = 'L';
                    break;
                default :
                    if (now == dominoes[i]) dominoes[i] = '.';
                    else if (now > 0 && now < dominoes[i]) dominoes[i] = 'L';
                    else dominoes[i] = 'R';
                    if (now > 0) ++now;
            } 
        }
        return dominoes;
    }
};
// @lc code=end

