/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
        int i(0);
        size_t pos(0);
        string S;
        for (auto& w : words) {
            pos = S.find(w);
            if (pos == string::npos || S[pos + w.size()] != '#') {
                S.append(w);
                S += '#';
            }
            //cout << w << '|' << S << endl;
        }
        return S.size();
    }
};
// @lc code=end

