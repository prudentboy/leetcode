/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int digit(1), base(1), zeros(1), delta(1);

        while (base < low) {
            base *= 10;
            base += ++digit;
            delta *= 10;
            ++delta;
        }
        delta /= 10;
        base /= 10;
        --digit;

        long long int num(0);
        while (num <= high) {
            for (int i(0); ; ++i) {
                num = base + i * delta;
                if (num % 10 == 0 || num > high) { break; }
                if (num >= low) { ans.push_back(num); }
            }
            base *= 10;
            base += ++digit;
            if (base > 123456789) { break; }
            delta *= 10;
            ++delta;
        }

        return ans;
    }
};
// @lc code=end

