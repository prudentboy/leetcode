/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n(arr.size());
        if (n <= 2) { return n - 1; }
        unordered_map<int, vector<int>> ump;
        for (int i(0); i < n; ++i) { ump[arr[i]].push_back(i); }

        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        int ans(0);
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                int idx(q.front());
                q.pop();
                if (idx == n - 1) { return ans; }
                for (int index : ump[arr[idx]]) {
                    if (visited[index]) { continue; }
                    q.push(index);
                    visited[index] = true;
                }
                ump.erase(arr[idx]);
                if (idx > 0 && !visited[idx - 1]) {
                    q.push(idx - 1);
                    visited[idx - 1] = true;
                }
                if (!visited[idx + 1]) {
                    q.push(idx + 1);
                    visited[idx + 1] = true;
                }
            }
            ++ans;
        }
        return 0;
    }
};
// @lc code=end

