/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans(0);
        int i(0), j(0), m(arr1.size()), n(arr2.size());
        if (d <= 0) { return m * n; }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (countDis(arr1[i], arr2[j]) <= d) { break; }
            }
            if (j == n) { ++ans; }
        }
        return ans;
    }
private:
    inline int countDis(int x, int y) {
        if (x < y) { return y - x; }
        return x - y;
    }
};
// @lc code=end

