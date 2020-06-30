/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            auto culDisSqure = [](const vector<int>& v) -> long long int {
                return (long long int)v[0] * v[0] + v[1] * v[1];
            };
            return culDisSqure(a) < culDisSqure(b);
        });
        points.resize(K);
        return points;
    }
};
// @lc code=end

