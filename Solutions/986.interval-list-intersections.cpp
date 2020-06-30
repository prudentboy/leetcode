/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;

        int i(0), j(0);
        vector<int> tmp(2, 0);

        while (i < A.size() && j < B.size()) {
            //cout << i << ':' << A[i][0] << ' ' << A[i][1] << '|';
            //cout << j << ':' << B[j][0] << ' ' << B[j][1] << endl;
            tmp[0] = max(A[i][0], B[j][0]);
            tmp[1] = min(A[i][1], B[j][1]);
            if (tmp[0] <= tmp[1]) { ans.push_back(tmp); }
            if (A[i][1] > B[j][1]) {
                ++j;
            } else if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++i;
                ++j;
            }
        }

        return ans;
    }
};
// @lc code=end

