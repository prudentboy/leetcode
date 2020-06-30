/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n, 0);
        int i(0), j(1);
        while (j <= n)
        {
            if (k-- > 0) ans[i++] = (k % 2 == 0 ? j++ : n--);
            else ans[i++] = j++;
        }
        return ans;
    }
};
// @lc code=end

