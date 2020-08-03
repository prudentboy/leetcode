/*
 * @lc app=leetcode id=1363 lang=cpp
 *
 * [1363] Largest Multiple of Three
 */

// @lc code=start
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnts(10);
        int sum(0);
        for (int digit : digits) {
            sum += digit;
            ++cnts[digit];
        }
        sum %= 3;
        if (sum > 0) {
            int i(1);
            for (; i < 9; ++i) {
                if (cnts[i] > 0 && i % 3 == sum) {
                    --cnts[i];
                    break;
                }
            }
            if (i == 9) {
                int cnt(2);
                for (i = 1; i < 9; ++i) {
                    while (cnts[i] > 0 && i % 3 + sum == 3 && cnt > 0) {
                        --cnts[i];
                        --cnt;
                    }
                }
            }
        }

        string ans;
        for (int i(9); i > 0; --i) {
            if (cnts[i] > 0) { ans += string(cnts[i], i + '0'); }
        }
        if (cnts[0] > 0) { ans += ans.empty() ? "0" : string(cnts[0], '0'); }
        return ans;
    }
};
// @lc code=end

