/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left(0), right(1);
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }

        int mid(0);
        while (left < right) {
            mid = left + ((right - left) >> 1);
            //cout << left << ' ' << mid << ' ' << right << endl;
            if (check(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool check(const vector<int>& weights, int D, const int C) {
        int now(0);
        for (int w : weights) {
            //cout << now << '-' << w << '-' << D << endl;
            if (now + w > C) {
                --D;
                now = w;
            } else {
                now += w;
            }
            if (D <= 0) { return false; }
        }
        return true;
    }
};
// @lc code=end

