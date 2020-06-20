/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if (words.size() < 2) { return words.size(); }

        vector<vector<pair<string, int>>> ump(17);
        for (string& word : words) { ump[word.size()].push_back({word, 1}); }

        int ans(1);
        for (int i(0); i < 17; ++i) {
            if (ump[i].empty()) { continue; }
            
            if (!ump[i - 1].empty()) {
                for (auto& now : ump[i]) {
                    for (auto& pre : ump[i - 1]) {
                        if (predecessorCheck(pre.first, now.first)) {
                            now.second = max(now.second, pre.second + 1);
                        }
                    }
                    ans = max(ans, now.second);
                }
            }
        }

        return ans;
    }
private:
    bool predecessorCheck(const string& pre, const string& now) {
        if (now.size() != pre.size() + 1) { return false; }

        int i(0), j(0);
        bool flag(false);
        while (i < pre.size() && j < now.size()) {
            if (pre[i] == now[j]) {
                ++i;
                ++j;
            } else {
                if (flag) { return false; }
                ++j;
                flag = true;
            }
        }

        return i == pre.size();
    }
};
// @lc code=end

