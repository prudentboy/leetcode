/*
 * @lc app=leetcode id=1255 lang=cpp
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnts(26);
        for (char c : letters) { ++cnts[c - 'a']; }

        vector<vector<int>> dict;
        for (auto& word : words) {
            vector<int> w(27);
            int point(0);
            for (char c : word) {
                ++w[c - 'a'];
                point += score[c - 'a'];
            }
            w.back() = point;
            dict.emplace_back(move(w));
        }

        int ans(0);
        function<void(int, int)> dfs = [&](int idx, int score) {
            if (idx == dict.size()) {
                ans = max(ans, score);
                return;
            }
            dfs(idx + 1, score);
            bool available(true);
            for (int i(0); i < 26; ++i) {
                cnts[i] -= dict[idx][i];
                if (cnts[i] < 0) { available = false; }
            }
            if (available) { dfs(idx + 1, score + dict[idx].back()); }
            for (int i(0); i < 26; ++i) { cnts[i] += dict[idx][i]; }
        };

        dfs(0, 0);
        return ans;
    }
};
// @lc code=end

