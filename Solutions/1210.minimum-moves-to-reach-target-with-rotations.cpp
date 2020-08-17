/*
 * @lc app=leetcode id=1210 lang=cpp
 *
 * [1210] Minimum Moves to Reach Target with Rotations
 */

// @lc code=start
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        const int n(grid.size());
        unordered_set<int> ust;
        queue<vector<int>> q;
        q.push({0, 0, 0, 1});
        ust.insert(getKey({0, 0, 0, 1}));
        int ans(0);
        int final(getKey({n - 1, n - 2, n - 1, n - 1}));
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                vector<int> cur(q.front());
                q.pop();
                if (getKey(cur) == final) { return ans; }
                for (auto& nxt : getValidNxt(grid, cur)) {
                    int key(getKey(nxt));
                    if (ust.count(key) > 0) { continue; }
                    q.push(nxt);
                    ust.insert(key);
                }
            }
            ++ans;
        }
        return -1;
    }
private:
    vector<vector<int>> getValidNxt(const vector<vector<int>>& grid, const vector<int>& snake) {
        vector<vector<int>> ret;
        vector<int> nxt(snake);
        // right
        ++nxt[1]; ++nxt[3];
        if (valid(grid, nxt)) { ret.push_back(nxt); }
        --nxt[1]; --nxt[3];
        // down
        ++nxt[0]; ++nxt[2];
        if (valid(grid, nxt)) { ret.push_back(nxt); }
        --nxt[0]; --nxt[2];
        // clockwise
        if (isHorizontal(snake)) {
            ++nxt[0]; ++nxt[2];
            if (!valid(grid, nxt)) { return ret; }
            --nxt[0]; --nxt[3];
            if (valid(grid, nxt)) { ret.push_back(nxt); }
        }
        // counterclockwise
        if (isVertical(snake)) {
            ++nxt[1]; ++nxt[3];
            if (!valid(grid, nxt)) { return ret; }
            --nxt[2]; --nxt[1];
            if (valid(grid, nxt)) { ret.push_back(nxt); }
        }
        return ret;
    }
    inline bool valid(const vector<vector<int>>& grid, const vector<int>& snake) {
        const int n(grid.size());
        if (snake[2] >= n || snake[3] >= n) { return false; }
        if (grid[snake[0]][snake[1]] == 1 || grid[snake[2]][snake[3]] == 1) { return false; }
        return true;
    }
    inline bool isHorizontal(const vector<int>& snake) {
        return snake[0] == snake[2] && snake[1] + 1 == snake[3];
    }
    inline bool isVertical(const vector<int>& snake) {
        return snake[0] + 1 == snake[2] && snake[1] == snake[3];
    }
    inline int getKey(const vector<int>& snake) {
        int tail(snake[0] * 100 + snake[1]);
        int head(snake[2] * 100 + snake[3]);
        return (tail << 15) | head;
    }
};
// @lc code=end

