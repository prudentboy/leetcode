/*
 * @lc app=leetcode id=1324 lang=cpp
 *
 * [1324] Print Words Vertically
 */

// @lc code=start
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;

        int i(0), j(0);
        for (char c : s) {
            //cout << i << ' ' << j << ' ' << c << endl;
            if (c == ' ') {
                i = 0;
                ++j;
            } else {
                while (ans.size() <= i) { ans.push_back(""); }
                //cout << ans.size() << endl;
                while (ans[i].size() <= j) { ans[i] += ' '; }
                //cout << ans[i].size() << endl;
                ans[i++][j] = c;
            }
            //printAns(ans);
        }
        return ans;
    }
private:
    void printAns(const vector<string>& ans) {
        for (const string& s : ans) {
            cout << '*' << s << endl;
        }
    }
};
// @lc code=end

