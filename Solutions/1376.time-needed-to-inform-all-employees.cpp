/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        int i(0);
        for (int parent : manager) {
            if (parent != -1) { children[parent].push_back(i); }
            ++i;
        }

        function<int(int)> calTime = [&](int head) -> int {
            int t(0);
            for (int child : children[head]) {
                t = max(t, calTime(child));
            }
            return t + informTime[head];
        };

        return calTime(headID);
    }
};
// @lc code=end

