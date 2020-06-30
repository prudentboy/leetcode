/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int ans(0);

        int n(grid.size());
        int i(0), j(0), k(0), tmp(0);
        unordered_map<int, int> ump;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < 4; ++k) {
                    tmp = getIndex(i, j, k);
                    ump[tmp] = tmp;
                }
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                switch (grid[i][j]) {
                    case '\\' :
                        ump[findGroup(getIndex(i, j, 0), ump)] = findGroup(getIndex(i, j, 1), ump);
                        ump[findGroup(getIndex(i, j, 2), ump)] = findGroup(getIndex(i, j, 3), ump);
                        break;
                    case '/' :
                        ump[findGroup(getIndex(i, j, 0), ump)] = findGroup(getIndex(i, j, 3), ump);
                        ump[findGroup(getIndex(i, j, 1), ump)] = findGroup(getIndex(i, j, 2), ump);
                        break;
                    case ' ':
                        ump[findGroup(getIndex(i, j, 0), ump)] = findGroup(getIndex(i, j, 1), ump);
                        ump[findGroup(getIndex(i, j, 1), ump)] = findGroup(getIndex(i, j, 2), ump);
                        ump[findGroup(getIndex(i, j, 2), ump)] = findGroup(getIndex(i, j, 3), ump);
                    default:
                        break;
                }
                if (i < n - 1) {
                    ump[findGroup(getIndex(i, j, 2), ump)] = findGroup(getIndex(i + 1, j, 0), ump); }
                if (j < n - 1) { 
                    ump[findGroup(getIndex(i, j, 1), ump)] = findGroup(getIndex(i, j + 1, 3), ump); }
            }
        }
/*
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < 4; ++k) {
                    tmp = getIndex(i, j, k);
                    if (findGroup(tmp, ump) == tmp) {
                        ++ans;
                    }
                }
            }
        }*/
        for (auto& p : ump) {
            if (p.first == p.second) { ++ans; }
        }
        return ans;
    }
private:
    int getIndex(int row, int col, int part) {
        return row * 1000 + col * 10 + part;
    }
    int findGroup(int index, unordered_map<int, int>& mp) {
        while (mp[index] != index) {
            index = mp[index];
        }
        return index;
    }
};
// @lc code=end

