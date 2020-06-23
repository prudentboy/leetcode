/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) { return true; }

        int n(arr.size());
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        int tmp(0);
        visited[start] = true;

        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (arr[tmp] == 0) { return true; }
            if (tmp + arr[tmp] < n && !visited[tmp + arr[tmp]]) {
                q.push(tmp + arr[tmp]);
                visited[tmp + arr[tmp]] = true;
            }
            if (tmp - arr[tmp] >= 0 && !visited[tmp - arr[tmp]]) {
                q.push(tmp - arr[tmp]);
                visited[tmp - arr[tmp]] = true;
            }
        }

        return false;
    }
};
// @lc code=end

