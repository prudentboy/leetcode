/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        size_t ans(0);
        int cnt(0);
        size_t i(0);
        unordered_map<int, size_t> m;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0) --cnt;
            else if (nums[i] == 1) ++cnt;
            if (cnt == 0) ans = max(ans, i + 1);
            else
            {
                if (m.count(cnt) == 0) m[cnt] = i;
                else ans = max(ans, i - m[cnt]);
            }
            //cout << i << ' ' << cnt << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

