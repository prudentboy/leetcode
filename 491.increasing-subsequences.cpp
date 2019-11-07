/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> now;
        findSubsequences(nums, ans, now, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
private:
    void findSubsequences(const vector<int>& nums, set<vector<int>>& ans, vector<int>& now, size_t start)
    {
        //for (int n : now) cout << n << ' ';
        //cout << endl;
        if (now.size() > 1) ans.insert(now);
        size_t i(0);
        for (i = start; i < nums.size(); ++i)
        {
            if (!now.empty() && now.back() > nums[i]) continue;
            now.push_back(nums[i]);
            findSubsequences(nums, ans, now, i + 1);
            now.pop_back();
        }
        return;
    }
};
// @lc code=end

