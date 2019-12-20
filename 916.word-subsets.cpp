/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int i(0);
        vector<int> totalCnt(26, 0), tmp(totalCnt);
        for (string& strB : B) {
            tmp = getLetterCnts(strB);
            for (i = 0; i < 26; ++i) {
                totalCnt[i] = max(totalCnt[i], tmp[i]);
            }
        }
        for (string& strA : A) {
            tmp = getLetterCnts(strA);
            for (i = 0; i < 26; ++i) {
                if (tmp[i] < totalCnt[i]) { break; }
            }
            if (i == 26) ans.push_back(strA);
        }
        return ans;
    }
private:
    vector<int> getLetterCnts(const string& s) {
        vector<int> ans(26, 0);
        for (char c : s) {
            ++ans[c - 'a'];
        }
        return ans;
    }
};
// @lc code=end

