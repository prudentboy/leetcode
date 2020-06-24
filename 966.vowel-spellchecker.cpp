/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int wLen(wordlist.size()), qLen(queries.size());
        vector<string> ans(qLen);

        unordered_map<string, unsigned int> ori, cap, vowel;

        int i(0);
        string tmp, noVow, vindex;
        for (i = 0; i < wLen; ++i) {
            if (ori.count(wordlist[i]) == 0) { ori[wordlist[i]] = i; }

            tmp.assign(getLower(wordlist[i]));
            if (cap.count(tmp) == 0) { cap[tmp] = i; }

            noVow.assign(getNoVow(tmp));
            if (vowel.count(noVow) == 0) { vowel[noVow] = i; }
        }

        for (i = 0; i < qLen; ++i) {
            if (ori.count(queries[i]) > 0) {
                ans[i] = wordlist[ori[queries[i]]];
            } else {
                tmp.assign(getLower(queries[i]));
                if (cap.count(tmp) > 0) {
                    ans[i] = wordlist[cap[tmp]];
                } else {
                    noVow.assign(getNoVow(tmp));
                    if (vowel.count(noVow) > 0) {
                        ans[i] = wordlist[vowel[noVow]];
                    } else {
                        ans[i] = "";
                    }
                }
            }
        }
        return ans;
    }
private:
    string getLower(const std::string& str) {
        string ans(str);
        for (int j = 0; j < ans.size(); ++j) { ans[j] |= ' '; }
        return ans;
    }
    string getNoVow(const std::string& lStr) {
        string ans;
        string vindex;
        for (int i(0); i < lStr.size(); ++i) {
            switch (lStr[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vindex.append(to_string(i));
                    break;
                default:
                    ans += lStr[i];
            }
        }
        ans.append(vindex);
        return ans;
    }
};
// @lc code=end

