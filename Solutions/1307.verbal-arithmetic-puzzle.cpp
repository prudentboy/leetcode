/*
 * @lc app=leetcode id=1307 lang=cpp
 *
 * [1307] Verbal Arithmetic Puzzle
 */

// @lc code=start
class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        vector<vector<char>> chars(result.size());
        vector<bool> isFirstNum(26, false);
        for (string& word : words) {
            if (word.size() > result.size()) { return false; }
            if (word.size() > 1) { isFirstNum[word[0] - 'A'] = true; }
            for (auto iter(word.rbegin()); iter != word.rend(); ++iter) {
                chars[iter - word.rbegin()].push_back(*iter);
            }
        }
        if (result.size() > 1) { isFirstNum[result.front() - 'A'] = true; }
        for (auto iter(result.rbegin()); iter != result.rend(); ++iter) {
            chars[iter - result.rbegin()].push_back(*iter);
        }
        
        vector<int> dict(26, -1);
        vector<bool> used(10, false);
        function<bool(int, int, int)> dfs = [&](int digit, int idx, int cur) {
            if (digit == chars.size()) { return cur == 0; }

            int v(-1);
            if (dict[chars[digit][idx] - 'A'] != -1) {
                v = dict[chars[digit][idx] - 'A'];
                if (idx + 1 == chars[digit].size()) {
                    if ((cur - v) % 10 != 0) { return false; }
                    return dfs(digit + 1, 0, (cur - v) / 10);
                } else {
                    return dfs(digit, idx + 1, cur + v);
                }
            } else {
                for (int i(0); i < 10; ++i) {
                    if (used[i]) { continue; }
                    if (i == 0 && isFirstNum[chars[digit][idx] - 'A']) { continue; }
                    v = dict[chars[digit][idx] - 'A'] = i;
                    used[i] = true;
                    if (idx + 1 == chars[digit].size()) {
                        if ((cur - v) % 10 != 0) {
                            dict[chars[digit][idx] -'A'] = -1;
                            used[i] = false;
                            continue;
                        }
                        if (dfs(digit + 1, 0, (cur - v) / 10)) { return true; }
                    } else {
                        if (dfs(digit, idx + 1, cur + v)) { return true; }
                    }
                    dict[chars[digit][idx] - 'A'] = -1;
                    used[i] = false;
                }
            }
            return false;
        };

        return dfs(0, 0, 0);
    }
};
// @lc code=end

