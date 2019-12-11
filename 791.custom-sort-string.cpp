/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> v(26, -1);
        int i(0);
        for (i = 0; i < S.size(); ++i) v[S[i] - 'a'] = i;
        sort(T.begin(), T.end(), [&](char a, char b) {
            //cout << a << ' ' << b << ' ' << v[a - 'a'] << ' ' << v[b - 'a'] << endl;
            if (v[a - 'a'] == v[b - 'a']) return a < b;
            if (v[a - 'a'] == -1) return false;
            if (v[b - 'a'] == -1) return true;
            return v[a - 'a'] < v[b - 'a'];
        });
        return T;
    }
};
// @lc code=end

