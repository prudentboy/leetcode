/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;

        istringstream iss(text);
        string s;
        bool hitFir(false);
        bool hitSec(false);

        while (iss >> s) {
            if (hitSec) { ans.push_back(s); }
            if (s == first) {
                hitFir = true;
                hitSec = false;
            } else if (s == second) {
                hitSec = hitFir;
                hitFir = false;
            } else {
                hitFir = false;
                hitSec = false;
            }
        }

        return ans;
    }
};
// @lc code=end

