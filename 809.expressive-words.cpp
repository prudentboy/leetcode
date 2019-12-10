/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans(0);
        for (const string& word : words) {
            if (match(S, word)) {
                //cout << word << endl;
                ++ans;
            }
        }
        return ans;
    }
private:
    bool match(const string& tar, const string& test) {
        if (test.size() > tar.size()) return false;
        if (test.size() == tar.size()) return test == tar;
        int i(0), j(0);
        int cntI(0), cntJ(0);
        while (i < tar.size() && j < test.size()) {
            if (tar[i] != test[j]) return false;
            cntI = cntJ = 1;
            ++i;
            ++j;
            while (i < tar.size() && tar[i] == tar[i - 1]) {
                ++cntI;
                ++i;
            }
            while (j < test.size() && test[j] == test[j - 1]) {
                ++cntJ;
                ++j;
            }
            //cout << cntI << ' ' << cntJ << endl;
            if (cntI == cntJ) continue;
            if (cntI < 3 || cntI < cntJ) return false;
        }
        return i == tar.size() && j == test.size();
    }
};
// @lc code=end

