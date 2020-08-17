/*
 * @lc app=leetcode id=1515 lang=cpp
 *
 * [1515] Best Position for a Service Centre
 */

// @lc code=start
class Solution {
struct Point {
    Point() : x(0.0), y(0.0) {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    Point(const vector<double>& p) : x(p[0]), y(p[1]) {}
    Point(const vector<int>& p) : x(static_cast<double>(p[0])), y(static_cast<double>(p[1])) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
    double x;
    double y;
};
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        const vector<vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        vector<Point> points(positions.size());
        for (int i(0); i < positions.size(); ++i) { points[i] = Point(positions[i]); }
        double ans(DBL_MAX), step(100), eps(1e-6);
        Point cur;
        bool can_reduce(false);
        while (step > eps) {
            can_reduce = false;
            for (auto& dir : dirs) {
                Point nxt(cur.x + dir[0] * step, cur.y + dir[1] * step);
                double tmp(calAllDis(points, nxt));
                if (tmp < ans) {
                    can_reduce = true;
                    ans = tmp;
                    cur.x = nxt.x;
                    cur.y = nxt.y;
                }
            }
            if (!can_reduce) { step /= 2; }
        }
        return ans;
    }
private:
    double calAllDis(const vector<Point>& points, const Point& p) {
        double ret(0.0);
        for (const Point& point : points) { ret += calDis(p, point); }
        return ret;
    }
    double calDis(const Point& p1, const Point& p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
};
// @lc code=end

