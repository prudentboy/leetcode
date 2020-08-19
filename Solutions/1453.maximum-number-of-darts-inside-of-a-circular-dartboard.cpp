/*
 * @lc app=leetcode id=1453 lang=cpp
 *
 * [1453] Maximum Number of Darts Inside of a Circular Dartboard
 */

// @lc code=start
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        const int n(points.size());
        const double thres(1e-9);

        vector<vector<double>> centers;
        for (int i(0); i < n; ++i) {
            for (int j(0); j < n; ++j) {
                if (i == j || distance(points[i][0], points[i][1], points[j][0], points[j][1]) - 2 * r > thres) { continue; }
                centers.emplace_back(getCenter(points[i], points[j], r));
            }
        }

        int ans(1);
        for (int i(0); i < centers.size(); ++i) {
            int cnt(0);
            for (int j(0); j < n; ++j) {
                if (distance(points[j][0], points[j][1], centers[i][0], centers[i][1]) - r < thres) { ++cnt; }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
private:
    double distance(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    vector<double> getCenter(const vector<int>& p1, const vector<int>& p2, const double r) {
        double d(distance(p1[0], p1[1], p2[0], p2[1]) / 2.0), h(sqrt(r * r - d * d));
        vector<double> M({(p1[0] + p2[0]) / 2.0, (p1[1] + p2[1]) / 2.0});
        vector<double> H({p1[1] * 1.0 - p2[1], p2[0] * 1.0 - p1[0]});
        double len(sqrt(H[0] * H[0] + H[1] * H[1]));
        H[0] *= h / len;
        H[1] *= h / len;
        return {H[0] + M[0], H[1] + M[1]};
    }
};
// @lc code=end

