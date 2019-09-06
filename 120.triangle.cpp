/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        int i, j;
        for (i = 1; i < triangle.size(); ++i)
        {
            for (j = 0; j < triangle[i].size(); ++j)
            {
                triangle[i][j] += triangleMin(triangle[i - 1], j);
            }
        }
        int min = triangle[i - 1][0];
        for (int k = 1; k < j; ++k)
        {
            if (triangle[i - 1][k] < min) min = triangle[i - 1][k];
        }
        return min;
    }
private:
    int triangleMin(const vector<int>& v, int i)
    {
        if (i >= v.size()) return v[i - 1];
        if (i < 1) return v[i];
        return min(v[i], v[i - 1]);
    }
};

