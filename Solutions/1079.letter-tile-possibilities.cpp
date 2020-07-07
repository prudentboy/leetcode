/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        
        const int n(tiles.size());
        vector<bool> visited(n, false);

        int ans(0);
        function<void(int)> dfs = [&](int idx) {
            if (idx > n) { return; }
            ++ans;

            for (int i = 0; i < n; ++i) {
                if (visited[i]) { continue; }
                if (i > 0 && !visited[i - 1] && tiles[i] == tiles[i - 1]) { continue; }
                visited[i] = true;
                dfs(idx + 1);
                visited[i] = false;
            }
        };

        dfs(0);

        return --ans;
    }
};
// @lc code=end

