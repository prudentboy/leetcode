/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int x(0), y(matrix[0].size() - 1);

        while (x < matrix.size() && y >= 0)
        {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) ++x;
            else --y;
        }

        return false;
    }
};

