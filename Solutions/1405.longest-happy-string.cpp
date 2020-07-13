/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;

        vector<int> rest({a, b, c});
        vector<char> letter({'a', 'b', 'c'});

        int i(0);
        int mxIdx(0), mnIdx(0), midIdx(0), idx(0);
        while (true) {
            mxIdx = max_element(rest.begin(), rest.end()) - rest.begin();
            mnIdx = min_element(rest.begin(), rest.end()) - rest.begin();
            for (i = 0; i < 3; ++i) {
                if (i != mnIdx && i != mxIdx) { midIdx = i; }
            }
            idx = mxIdx;
            if (ans.size() > 1 && ans[ans.size() - 1] == letter[mxIdx] && ans[ans.size() - 2] == letter[mxIdx]) { idx = midIdx; }
            if (rest[idx] == 0) { break; }
            ans += letter[idx];
            --rest[idx];
        }
        return ans;
    }
};
// @lc code=end

