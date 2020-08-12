/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string_view, int> ump;
        int idx(0);
        for (string_view skill : req_skills) { ump[skill] = idx++; }

        int bitValue(0);
        vector<int> persons;
        for (auto& person : people) {
            bitValue = 0;
            for (string_view skill : person) { if (ump.count(skill)) { bitValue |= (1 << ump[skill]); } }
            persons.push_back(bitValue);
        }

        int goal((1 << req_skills.size()) - 1);
        vector<int> dp(goal + 1, -1);
        unordered_map<int, vector<int>> team;
        dp[0] = 0;
        team[0] = {};

        for (int i(0); i < people.size(); ++i) {
            if (persons[i] == 0) { continue; }
            for (int j(0); j <= goal; ++j) {
                if (dp[j] < 0) { continue; }
                int new_state(j | persons[i]);
                if (dp[new_state] < 0 || dp[new_state] > dp[j] + 1) {
                    dp[new_state] = dp[j] + 1;
                    team[new_state] = team[j];
                    team[new_state].emplace_back(i);
                }
            }
        }
        return team[goal];
    }
};
// @lc code=end

