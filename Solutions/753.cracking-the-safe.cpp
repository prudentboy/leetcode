/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 */

// @lc code=start
class Solution {
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        unordered_set<string> ust;
        ust.insert(ans);

        int count(pow(k, n));
        for (int i(0); i < count; ++i) {
            string tmp(ans.substr(ans.size() - n + 1, n - 1));
            tmp += ' ';
            for (int j(k - 1); j >= 0; --j) {
                tmp.back() = j + '0';
                if (ust.count(tmp) == 0) {
                    ans += tmp.back();
                    ust.insert(tmp);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

