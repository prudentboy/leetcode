/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i(0); i < profit.size(); ++i) { jobs.push_back({endTime[i], startTime[i], profit[i]}); }
        sort(jobs.begin(), jobs.end());

        map<int, int> dp;
        dp[0] = 0;
        for (auto& job : jobs) {
            auto iter(prev(dp.upper_bound(job[1])));
            int pro(iter->second + job[2]);
            if (pro > dp.rbegin()->second) { dp[job.front()] = pro; }
        }
        return dp.rbegin()->second;
    }
};
// @lc code=end

