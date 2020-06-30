/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return;
        _cumSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i(0); i < matrix.size(); ++i)
        {
            for (int j(0); j < matrix[0].size(); ++j)
            {
                //cout << i << ' ' << j << endl;
                _cumSum[i + 1][j + 1] = matrix[i][j] + _cumSum[i][j + 1] + _cumSum[i + 1][j] - _cumSum[i][j];
            }
        }
        //cout << "cons success" << endl;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout << "sum success" << endl;
        if (_cumSum.empty() || _cumSum[0].empty()) return 0;
        return _cumSum[row2 + 1][col2 + 1] + _cumSum[row1][col1] - _cumSum[row2 + 1][col1] - _cumSum[row1][col2 + 1];
    }
private:
    vector<vector<int>> _cumSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

