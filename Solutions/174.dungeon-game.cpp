/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        if (dungeon.empty() or dungeon[0].empty()) return 1;

        int m(dungeon.size()), n(dungeon[0].size());
        vector<vector<int>> table(m, vector<int>(n, 0));

        int tmp(1);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i == m - 1 and j == n - 1) tmp = max(1, 1 - dungeon[i][j]);
                else if (i + 1 >= m) tmp = max(1, table[i][j + 1] - dungeon[i][j]);
                else if (j + 1 >= n) tmp = max(1, table[i + 1][j] - dungeon[i][j]);
                else
                {
                    tmp = min(table[i][j + 1], table[i + 1][j]);
                    tmp = max(1, tmp - dungeon[i][j]);
                }
                table[i][j] = tmp;
            }
        }
        return table[0][0];
    }
};

