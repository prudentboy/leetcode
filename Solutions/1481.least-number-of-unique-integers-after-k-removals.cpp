/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq, cnts;
        for (int n : arr) { ++freq[n]; }
        for (auto& p : freq) { ++cnts[p.second]; }
        if (k == 0) { return freq.size(); }
        if (k == arr.size()) { return 0; }
        
        int mn(INT_MAX), mx(INT_MIN);
        map<int, int> cntMap;
        for (auto& p : cnts) {
            cntMap[p.first] = p.second;
        }

        int ans(freq.size());
        for (auto& p : cntMap) {
            //cout << p.first << ' ' << p.second << ' ' << k << ' ' << ans << endl;
            if (p.first > k) { return ans; }
            if (k >= p.first * p.second) {
                k -= p.first * p.second;
                ans -= p.second;
            } else {
                ans -= k / p.first;
                return ans;
            }
        }

        return ans;
    }
};
// @lc code=end

