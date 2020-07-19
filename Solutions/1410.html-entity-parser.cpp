/*
 * @lc app=leetcode id=1410 lang=cpp
 *
 * [1410] HTML Entity Parser
 */

// @lc code=start
class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> dict({ \
            {"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'}, \
            {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}});
        
        size_t idx;
        string ans, tmp;
        for (int i(0); i < text.size(); ++i) {
            if (text[i] == '&') {
                idx = text.find(';', i);
                if (idx != string::npos && idx - i < 7) {
                    tmp.assign(text.substr(i, idx - i + 1));
                    //cout << tmp << endl;
                    if (dict.count(tmp) > 0) {
                        ans += dict[tmp];
                        i = idx;
                        continue;
                    }
                }
            }
            ans += text[i];
        }

        return ans;
    }
};
// @lc code=end

