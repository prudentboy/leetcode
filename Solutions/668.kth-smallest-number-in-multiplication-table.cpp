/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l(1), r(m * n + 1), mid(0);
        while (l < r) {
            mid = l + ((r - l) >> 1);
            if (validCheck(m, n, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool validCheck(const int m, const int n, const int k, const int can) {
        int cnt(0);
        for (int i(1); i <= m; ++i) {
            if (i > can) { break; }
            cnt += min(n, can / i);
            if (cnt >= k) { return true; }
        }
        return cnt >= k;
    }
};
// @lc code=end
