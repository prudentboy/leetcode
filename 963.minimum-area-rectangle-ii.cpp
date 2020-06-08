/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

// @lc code=start
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        double minArea(DBL_MAX);

        unordered_set<string> posSet;
        for (auto& p : points) {
            posSet.insert(to_string(p[0]) + "-"  + to_string(p[1]));
        }

        int n(points.size());
        int i(0), j(0), k(0), dotProduct(0);
        vector<int> p4({0, 0});
        double areaSquare(0.0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) { continue; }
                for (k = 0; k < n; ++k) {
                    if (i == k || j == k) { continue; }
                    const auto& p1 = points[i];
                    const auto& p2 = points[j];
                    const auto& p3 = points[k];
                    dotProduct = (p1[0] - p2[0]) * (p3[0] - p2[0]) \
                               + (p1[1] - p2[1]) * (p3[1] - p2[1]);
                    if (dotProduct != 0) { continue; }
                    p4[0] = p1[0] + p3[0] - p2[0];
                    p4[1] = p1[1] + p3[1] - p2[1];
                    if (posSet.count(to_string(p4[0]) + "-" + to_string(p4[1])) == 0) { continue; }
                    areaSquare = (pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)) \
                               * (pow(p3[0] - p2[0], 2) + pow(p3[1] - p2[1], 2));
                    minArea = min(minArea, areaSquare);
                }
            }
        }
        return minArea == DBL_MAX ? 0 : sqrt(minArea);
    }
};
// @lc code=end

