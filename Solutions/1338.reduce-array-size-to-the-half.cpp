/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> cnts(arr.size() + 1);
        unordered_map<int, int> ump;
        for (int n : arr) { ++ump[n]; }
        for (auto& p : ump) { ++cnts[p.second]; }
        int cnt(0), ans(0);
        for (int i = arr.size(); i >= 0; --i) {
            while (cnts[i]-- > 0) {
                cnt += i;
                ++ans;
                if (arr.size() - cnt <= cnt) { return ans; }
            }
        }
        return 0;
    }
};
// @lc code=end

