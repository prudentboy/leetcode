/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */

// @lc code=start
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItems(m + 1);
        for (int i(0); i < group.size(); ++i) {
            if (group[i] == -1) { group[i] = m; }
            groupItems[group[i]].emplace_back(i);
        }

        vector<int> groupInDegree(m + 1), itemInDegree(n);
        vector<unordered_set<int>> groupGraph(m + 1);
        vector<vector<int>> itemGraph(n);

        for (int i(0); i < beforeItems.size(); ++i) {
            int gin(group[i]);
            for (int item : beforeItems[i]) {
                int gout(group[item]);
                if (gin == gout) {
                    ++itemInDegree[i];
                    itemGraph[item].emplace_back(i);
                    continue;
                }
                if (groupGraph[gout].count(gin) > 0) { continue; }
                ++groupInDegree[gin];
                groupGraph[gout].insert(gin);
            }
        }

        vector<int> ans;
        int gCnt(0), itemCnt(0);
        queue<int> groupQ;
        for (int i(0); i <= m; ++i) { if (groupInDegree[i] == 0) { groupQ.push(i); } }
        while (!groupQ.empty()) {
            int g(groupQ.front());
            groupQ.pop();
            // sort group g to ans
            queue<int> itemQ;
            for (int item : groupItems[g]) { if (itemInDegree[item] == 0) { itemQ.push(item); } }
            itemCnt = 0;
            while (!itemQ.empty()) {
                int it(itemQ.front());
                itemQ.pop();
                ans.emplace_back(it);
                for (int nxt : itemGraph[it]) {
                    if (--itemInDegree[nxt] == 0) { itemQ.push(nxt); }
                }
                ++itemCnt;
            }
            if (itemCnt < groupItems[g].size()) { return {}; }
            // update groupQ
            for (int ng : groupGraph[g]) {
                if (--groupInDegree[ng] == 0) { groupQ.push(ng); }
            }
            ++gCnt;
        }
        if (gCnt < m + 1) { return {}; }
        return ans;
    }
};
// @lc code=end

