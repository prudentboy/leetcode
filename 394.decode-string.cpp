/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        if (s.empty()) return s;
        cout << "begin: " << s << endl;

        string ans, tmp;
        int cnt(0);
        size_t i(0), begin(0), end(0);

        while (i < s.size())
        {
            begin = s.find_first_of("[", i);
            if (begin == string::npos)
            {
                ans.append(s, i, s.size() - i);
                break;
            }
            else
            {
                while (i < s.size() && !isdigit(s[i])) ans += s[i++];
                cnt = stoi(s.substr(i, begin - i));
                end = getEndBracketIndex(s, begin);
                tmp.assign(decodeString(s.substr(begin + 1, end - begin - 1)));
                while (cnt-- > 0) ans.append(tmp);
                i = end + 1;
            }
            //cout << i << ' ' << ans << endl;
        }
        
        return ans;
    }
private:
    size_t getEndBracketIndex(const string& s, size_t beg)
    {
        int cnt(1);
        for (size_t i(beg + 1); i < s.size(); ++i)
        {
            if (s[i] == '[') ++cnt;
            else if (s[i] == ']') --cnt;
            if (cnt == 0) return i;
        }
        return beg;
    }
};
// @lc code=end

