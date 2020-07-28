/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;

        auto match = [&]() -> int {
            int i(0), j(0);
            for (i = 0; i <= target.size() - stamp.size(); ++i) {
                int starCnt(0);
                for (j = 0; j < stamp.size(); ++j) {
                    if (target[i + j] == '*') {
                        ++starCnt;
                        continue;
                    }
                    if (target[i + j] != stamp[j]) { break; }
                }
                if (j == stamp.size() && starCnt != stamp.size()) { break; }
            }
            if (i <= target.size() - stamp.size()) {
                fill(target.begin() + i, target.begin() + i + stamp.size(), '*');
                return i;
            }
            return -1;
        };

        string result(target.size(), '*');
        while (true) {
            bool noMatch(true);
            if (target == result) { break; }
            int m(match());
            if (m == -1) { return {}; }
            ans.push_back(m); 
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

