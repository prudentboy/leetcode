/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowUmp({{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}});
        vector<int> states(32, s.size());
        states[0] = -1;
        int state(0), ans(0);
        for (int i(0); i < s.size(); ++i) {
            if (vowUmp.count(s[i]) > 0) { state ^= 1 << vowUmp[s[i]]; }
            if (states[state] == s.size()) { states[state] = i; }
            ans = max(ans, i - states[state]);
        }
        return ans;
    }
};
// @lc code=end

