/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans(0), n(row.size());
        for (int i(0); i < n; i += 2) {
            if (row[i + 1] == (row[i] ^ 1)) { continue; }
            for (int j = i + 2; j < n; ++j) {
                if (row[j] == (row[i] ^ 1)) {
                    swap(row[j], row[i + 1]);
                    break;
                }
            }
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

