/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3) { return false; }

        int i(0);
        int sum(0);
        for (i = 0; i < A.size(); ++i) {
            sum += A[i];
        }

        if (sum % 3 != 0) { return false; }
        sum /= 3;

        int now(0), cnt(0);
        for (i = 0; i < A.size(); ++i) {
            now += A[i];
            if (now == sum) {
                ++cnt;
                now = 0;
            }
        }

        return cnt == 3 || (sum == 0 && cnt > 3);
    }
};
// @lc code=end

