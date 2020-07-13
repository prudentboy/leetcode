/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
class Solution {
public:
    string getHappyString(int n, int k) {
        if (3 * (1 << (n - 1)) < k) { return ""; }
        string cur, ans;
        function<void(void)> dfs = [&]() {
            //cout << cur << '*' << endl;
            if (!ans.empty()) { return; }
            if (cur.size() == n) {
                if (--k == 0) { ans.assign(cur); }
                return;
            }
            for (char c('a'); c <= 'c'; ++c) {
                if (!cur.empty() && cur.back() == c) { continue; }
                cur += c;
                dfs();
                cur.pop_back();
            }
        };

        dfs();

        return ans;
    }
};
// @lc code=end

