/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> ump;
        int bitValue(0);
        for (string& word : words) {
            bitValue = 0;
            for (char c : word) { bitValue |= (1 << (c - 'a')); }
            ++ump[bitValue];
        }

        vector<int> ans;
        bitValue = 0;
        int ret(0);
        function<void(string_view, int)> dfs = [&](string_view s, int idx) {
            if (idx == 7) {
                if ((bitValue & (1 << (s.front() - 'a'))) > 0 && ump.count(bitValue) > 0) { ret += ump[bitValue]; }
                return;
            }
            dfs(s, idx + 1);
            bitValue ^= (1 << (s[idx] - 'a'));
            dfs(s, idx + 1);
            bitValue ^= (1 << (s[idx] - 'a'));
        };

        for (string& puzzle : puzzles) {
            ret = 0;
            dfs(puzzle, 0);
            ans.push_back(ret);
        }

        return ans;
    }
};
// @lc code=end

