/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */

// @lc code=start
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<string> block_set;
        for (auto& point : blocked) { block_set.insert(getSetKey(point)); }
        if (block_set.count(getSetKey(source)) > 0 || block_set.count(getSetKey(target)) > 0) { return false; }

        const int N(1000000), b(block_set.size());
        const vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        function<bool(int, int, int, int)> dfs = [&](int x, int y, int tx, int ty) {
            queue<pair<int, int>> q;
            unordered_set<string> visited;
            q.push({x, y});
            visited.insert(getSetKey({x, y}));
            int cnt(1);
            pair<int, int> tmp;
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                if (tmp.first == tx && tmp.second == ty) { return true; }
                int nx(0), ny(0);
                for (int i(0); i < 4; ++i) {
                    nx = tmp.first + dir[i][0];
                    ny = tmp.second + dir[i][1];
                    string key(getSetKey({nx, ny}));
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited.count(key) > 0 || block_set.count(key) > 0) { continue; }
                    q.push({nx, ny});
                    ++cnt;
                    visited.insert(key);
                }
                if (cnt > ((b * (b - 1)) >> 1)) { return true; }
            }
            return false;
        };

        return dfs(source[0], source[1], target[0], target[1]) && dfs(target[0], target[1], source[0], source[1]);
    }
private:
    inline string getSetKey(const vector<int>& point) {
        string ret(to_string(point.front()));
        ret += ',';
        ret += to_string(point.back());
        return ret;
    }
};
// @lc code=end

