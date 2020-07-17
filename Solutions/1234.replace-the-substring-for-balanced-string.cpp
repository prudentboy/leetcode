/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> letterMap({{'Q', 0}, {'W', 1}, {'E', 2}, {'R', 3}});
        vector<int> cnts(4, -(s.size() >> 2)), window(4);

        for (char c : s) {
            ++cnts[letterMap[c]];
        }

        int ans(s.size());

        auto check = [&]() -> bool {
            for (int k(0); k < 4; ++k) {
                if (window[k] < cnts[k]) { return false; }
            }
            return true;
        };

        int i(0), j(0);
        for (i = 0; i < s.size(); ++i) {
            ++window[letterMap[s[i]]];
            if (!check()) { continue; }
            while (check()) { --window[letterMap[s[j++]]]; }
            ans = min(ans, i - j + 2);
        }

        return ans;
    }
};
// @lc code=end

