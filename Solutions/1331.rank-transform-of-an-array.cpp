/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) { return arr; }
        
        vector<int> ans(arr);
        sort(ans.begin(), ans.end());
        unordered_map<int, int> mp;
        int rank(1);
        mp[ans.front()] = 1;
        for (int i(1); i < ans.size(); ++i) {
            if (ans[i] == ans[i - 1]) { continue; }
            mp[ans[i]] = ++rank;
        }
        for (int i(0); i < arr.size(); ++i) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};
// @lc code=end

