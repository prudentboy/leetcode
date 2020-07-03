/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& lft, const string& rght) {
            return lft.size() < rght.size();
        });
        vector<string> ans;
        int i(0), j(0);
        for (i = 0; i < words.size() - 1; ++i) {
            for (j = i + 1; j < words.size(); ++j) {
                if (isSubstr(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
private:
    bool isSubstr(const string& shrt, const string& lng) {
        if (shrt.size() > lng.size()) { return false; }
        return lng.find(shrt) != string::npos;
    }
};
// @lc code=end

