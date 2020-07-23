/*
 * @lc app=leetcode id=1476 lang=cpp
 *
 * [1476] Subrectangle Queries
 */

// @lc code=start
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rec_(rectangle) {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        update_his_.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (auto iter(update_his_.rbegin()); iter != update_his_.rend(); ++iter) {
            auto& record(*iter);
            if (row >= record[0] && row <= record[2] && col >= record[1] && col <= record[3]) { return record[4]; }
        }
        return rec_[row][col];
    }
private:
    vector<vector<int>> rec_;
    vector<vector<int>> update_his_;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end

