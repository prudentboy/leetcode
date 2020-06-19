/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> arr(hi - lo + 1);
        for (int i(0); i < arr.size(); ++i) { arr[i] = lo + i; }

        auto calPow = [](int n) -> int {
            int pow(0);
            while (n != 1) {
                ++pow;
                n = (n & 1) ? (3 * n + 1) : (n >> 1);
            }
            return pow;
        };

        sort(arr.begin(), arr.end(), [&](const int left, const int right) {
            int powLeft(calPow(left)), powRight(calPow(right));
            if (powLeft == powRight) { return left < right; }
            return powLeft < powRight;
        });

        return arr[k - 1];
    }
};
// @lc code=end

