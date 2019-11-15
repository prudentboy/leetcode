/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.empty() || wall[0].empty()) return 0;

        long long int len(0);
        long long int i(0), j(0);
        for (i = 0; i < wall[0].size(); ++i) len += wall[0][i];
        //cout << len << endl;

        unordered_map<long long int, int> lines;

        long long int sum(0);
        for (i = 0; i < wall.size(); ++i)
        {
            sum = 0;
            for (j = 0; j < wall[i].size(); ++j)
            {
                sum += wall[i][j];
                //cout << sum << ' ';
                ++lines[sum];
                //cout << lines[sum] << endl;
            }
        }

        long long int max(0);
        for (const auto& p : lines) if (p.first != len && p.second > max) max = p.second;
        return wall.size() - max;
    }
};
// @lc code=end

