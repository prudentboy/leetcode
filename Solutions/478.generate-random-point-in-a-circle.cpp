/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
class Solution {
public:
    Solution(double radius, double x_center, double y_center) : r_(radius), x_(x_center), y_(y_center) {
        srand(time(nullptr));
    }
    
    vector<double> randPoint() {
        double r(r_ * sqrt((double)rand() / RAND_MAX)), theta(2 * M_PI * (double)rand() / RAND_MAX);
        return {x_ + r * cos(theta), y_ + r * sin(theta)};
    }
private:
    double r_;
    double x_;
    double y_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

