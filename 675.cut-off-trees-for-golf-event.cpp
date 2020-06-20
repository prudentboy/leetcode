/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 */

// @lc code=start
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m(forest.size()), n(forest[0].size());
        //map<int, pair<int, int>> mp;
        map<int, pair<int, int>> mp;
        
        int ans(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    mp[forest[i][j]] = {i, j};
                }
            }
        }

        int dis(0);
        pair<int, int> pos({0, 0});
        for (auto& tree : mp) {
            //cout << pos.first << ' ' << pos.second << endl;
            //cout << tree.second.first << ' ' << tree.second.second << ':' << tree.first << endl;
            dis = cntDistance(pos, tree.second, forest);
            //cout << dis << endl;
            if (dis == -1) { return -1; }
            ans += dis; 
            pos = tree.second;
        }

        return ans;
    }
private:
    int cntDistance(const pair<int, int>& beg, const pair<int, int>& end, const vector<vector<int>>& forest) {
        int m(forest.size()), n(forest[0].size());

        vector<vector<int>> table(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        pair<int, int> tmp({0, 0});

        int cnt(0);
        int len(0);
        q.emplace(beg);
        table[beg.first][beg.second] = 1;

        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();

                if (tmp == end) { return cnt; }

                int &i = tmp.first;
                int &j = tmp.second;

                if (i > 0 && forest[i - 1][j] != 0 && table[i - 1][j] == 0) {
                    q.emplace(i - 1, j);
                    table[i - 1][j] = 1;
                }
                if (j > 0 && forest[i][j - 1] != 0 && table[i][j - 1] == 0) {
                    q.emplace(i, j - 1);
                    table[i][j - 1] = 1;
                }
                if (i < m - 1 && forest[i + 1][j] != 0 && table[i + 1][j] == 0) {
                    q.emplace(i + 1, j);
                    table[i + 1][j] = 1;
                }
                if (j < n - 1 && forest[i][j + 1] != 0 && table[i][j + 1] == 0) {
                    q.emplace(i, j + 1);
                    table[i][j + 1] = 1;
                }
            }

            ++cnt;
        }

        return -1;
    }
};
// @lc code=end

