/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left(-1);
        long right(1), mid(0);

        for (int n : nums) {
            left = max(left, n);
            right += n;
        }

        int subCnt(0);
        long sum(0);
        while (left < right) {
            mid = left + ((right - left) >> 1);
            sum = 0;
            subCnt = 1;
            for (int n : nums) {
                if (sum + n > mid) {
                    sum = n;
                    ++subCnt;
                } else {
                    sum += n;
                }
            }
            //cout << left << ' ' << right << ' ' << mid << ' ' << subCnt << endl;
            if (subCnt > m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
// @lc code=end

