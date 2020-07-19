/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n(bloomDay.size());
        if (n < (long long int)m * k) { return -1; }

        auto check = [&](int tempt) {
            int cnt(0);
            int i(0), j(0);
            for (i = 0; i + k <= n; ++i) {
                for (j = i; j < i + k; ++j) {
                    if (bloomDay[j] > tempt) { break; }
                }
                if (j == i + k) {
                    if (++cnt == m) { return true; }
                    --j;
                }
                i = j;
            }

            return false;
        };

        int mid(0), left(1), right(*max_element(bloomDay.begin(), bloomDay.end()));
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

