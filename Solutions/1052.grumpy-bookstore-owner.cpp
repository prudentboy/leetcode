/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n(customers.size());
        int base(0), more(0), now(0);
        int i(0), j(0);

        for (i = 0; i < n; ++i) { base += customers[i] * (grumpy[i] ^ 1); }
        for (i = 0; i < n; ++i) {
            now += customers[i] * grumpy[i];
            if (i - j >= X) {
                now -= customers[j] * grumpy[j];
                ++j;
            }
            more = max(more, now);
        }

        return base + more;
    }
};
// @lc code=end

