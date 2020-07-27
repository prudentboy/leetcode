/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */

// @lc code=start
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int n(graph.size());
        vector<vector<vector<int>>> memo((n << 1) + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        function<int(int, int, int)> play = [&](int steps, int mouse, int cat) {
            if (steps == (n << 1)) { return 0; }
            if (mouse == 0) { return 1; }
            if (mouse == cat) { return 2; }
            if (memo[steps][mouse][cat] != -1) { return memo[steps][mouse][cat]; }

            if ((steps & 1) == 0) { // mouse move
                int ret(2);
                for (int nxt : graph[mouse]) {
                    int nRes(play(steps + 1, nxt, cat));
                    if (nRes == 1) { return memo[steps][mouse][cat] = 1; }
                    if (nRes == 0) { ret = 0; }
                }
                return memo[steps][mouse][cat] = ret;
            } else {
                int ret(1);
                for (int nxt : graph[cat]) {
                    if (nxt == 0) { continue; }
                    int nRes(play(steps + 1, mouse, nxt));
                    if (nRes == 2) { return memo[steps][mouse][cat] = 2; }
                    if (nRes == 0) { ret = 0; }
                }
                return memo[steps][mouse][cat] = ret;
            }
        };

        return play(0, 1, 2);
    }
};
// @lc code=end

