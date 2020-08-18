/*
 * @lc app=leetcode id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */

// @lc code=start
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        if (initialBoxes.empty()) { return 0; }

        const int n(status.size());
        vector<bool> keyList(n, false);
        vector<bool> boxList(n, false);
        vector<bool> foundBox(n, false);
        queue<int> q;
        for (int box : initialBoxes) {
            foundBox[box] = true;
            q.push(box);
        }

        int ans(0);
        while (!q.empty()) {
            int box(q.front());
            q.pop();
            if (boxList[box]) { continue; }
            if (status[box] == 1 || keyList[box]) {
                ans += candies[box];
                boxList[box] = true;
                for (int b : containedBoxes[box]) {
                    if (boxList[b]) { continue; }
                    foundBox[b] = true;
                    q.push(b);
                }
                for (int b : keys[box]) {
                    keyList[b] = true;
                    if (!foundBox[b] || boxList[b]) { continue; }
                    q.push(b);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

