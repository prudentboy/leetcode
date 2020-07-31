/*
 * @lc app=leetcode id=761 lang=cpp
 *
 * [761] Special Binary String
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string S) {
        return helper(S);
    }
private:
    string helper(string_view s) {
        if (s.empty()) return "";
        //cout << s << endl;
        int cnt(0), i(0);
        vector<string> vec;
        for (int j(0); j < s.size(); ++j) {
            cnt += s[j] == '1' ? 1 : -1;
            if (cnt == 0) {
                vec.push_back('1' + helper(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }

        string ret;
        sort(vec.begin(), vec.end());
        for (auto it(vec.rbegin()); it != vec.rend(); ++it) {
            ret += (*it);
        }
        return ret;
    }
};
// @lc code=end

