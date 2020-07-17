/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bitStrs, strLens;

        int bitStr(0);
        bool flag(false);
        for (auto& str : arr) {
            bitStr = 0;
            flag = false;
            for (char c : str) {
                if ((bitStr & (1 << (c - 'a'))) != 0) {
                    flag = true;
                    break;
                }
                bitStr |= 1 << (c - 'a');
            }
            if (flag) { continue; }
            bitStrs.push_back(bitStr);
            strLens.push_back(str.size());
        }
        //for (int bs : bitStrs) { cout << setbase(16) << bs << ' '; }

        int ans(0);
        function<void(int, int, int)> dfs = [&](int len, int idx, int cur) {
            if (idx == bitStrs.size()) {
                ans = max(ans, len);
                return;
            }
            dfs(len, idx + 1, cur);
            if ((cur & bitStrs[idx]) == 0) {
                len += strLens[idx];
                cur |= bitStrs[idx];
                dfs(len, idx + 1, cur);
                cur ^= bitStrs[idx];
                len -= strLens[idx];
            }
        };

        dfs(0, 0, 0);
        
        return ans;
    }
};
// @lc code=end

