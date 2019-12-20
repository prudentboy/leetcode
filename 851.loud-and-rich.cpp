/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n(quiet.size());
        vector<int> richerCnt(n, 0);
        vector<unordered_set<int>> rich(n);
        for (auto& p : richer) {
            rich[p[0]].insert(p[1]);
            ++richerCnt[p[1]];
        }
        queue<int> q;
        vector<int> ans(n, -1);
        for (int i(0); i < n; ++i) {
            ans[i] = i;
            if (richerCnt[i] == 0) q.push(i);
        }
        int tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            for (int idx : rich[tmp]) {
                if (quiet[ans[idx]] > quiet[ans[tmp]]) ans[idx] = ans[tmp];
                if (--richerCnt[idx] == 0) q.push(idx);
            }
        }

        return ans;
    }
};
// @lc code=end

