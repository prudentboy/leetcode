/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() < 2 || timePoints.size() > 1440) return 0;

        int ans(1500), tmp(0);
        vector<int> tps(1440, 0);
        for (const string& t : timePoints)
        {
            tmp = getTimeFromStr(t);
            if (tps[tmp] > 0) return 0;
            tps[tmp] = 1;
        }
        int i(0);
        int start(-1), end(-1);
        for (i = 0; i < tps.size(); ++i) if (tps[i] > 0) break;
        start = i;
        end = i;
        tmp = start;
        for (i = start + 1; i < tps.size(); ++i)
        {
            if (tps[i] == 0) continue;
            end = max(end, i);
            ans = min(ans, i - tmp);
            tmp = i;
        }
        return min(ans, start + 1440 - end);
    }
private:
    int getTimeFromStr(const string& s)
    {
        return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }
};
// @lc code=end

