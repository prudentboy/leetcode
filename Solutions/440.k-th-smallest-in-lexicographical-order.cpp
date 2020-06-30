/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur(1);
        --k;

        long long int childNum(0), now(0), next(0);
        while (k > 0) {
            childNum = 0;
            now = cur;
            next = cur + 1;
            while (now <= n) {
                childNum += min((long long int)n + 1, next) - now;
                now *= 10;
                next *= 10;
            }
            if (childNum <= k) {
                k -= childNum;
                ++cur;
            } else {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};
// @lc code=end

