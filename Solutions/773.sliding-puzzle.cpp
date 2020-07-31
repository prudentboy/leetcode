/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> solved({{1, 2, 3}, {4, 5, 0}});

        const vector<vector<pair<int, int>>> dir({{{1, 0}, {0, 1}}, {{1, 0}, {0, -1}, {0, 1}}, \
                                                  {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, \
                                                  {{-1, 0}, {0, -1}, {0, 1}}, {{-1, 0}, {0, -1}}});
        queue<vector<vector<int>>> q;
        q.push(solved);
        unordered_set<int> ust;
        ust.insert(123450);
        int query(getVecNum(board));
        int len(0), ans(0);
        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                vector<vector<int>> tmp(q.front());
                q.pop();
                int cur(getVecNum(tmp));
                //cout << cur << endl;
                if (getVecNum(tmp) == query) { return ans; }
                int i(0);
                for (; i < 6; ++i) {
                    if (tmp[i / 3][i % 3] == 0) { break; }
                }
                for (auto p : dir[i]) {
                    int nx = i / 3 + p.first;
                    int ny = i % 3 + p.second;
                    swap(tmp[i / 3][i % 3], tmp[nx][ny]);
                    int nnum(getVecNum(tmp));
                    if (ust.count(nnum) == 0) {
                        ust.insert(nnum);
                        q.push(tmp);
                    }
                    swap(tmp[i / 3][i % 3], tmp[nx][ny]);
                }
            }
            ++ans;
        }
        return -1;
    }
private:
    inline int getVecNum(const vector<vector<int>>& state) {
        return state[0][0] * 100000 + state[0][1] * 10000 + state[0][2] * 1000 + \
               state[1][0] * 100 + state[1][1] * 10 + state[1][2];
    }
};
// @lc code=end

