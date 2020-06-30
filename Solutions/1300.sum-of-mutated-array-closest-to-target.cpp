/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n(arr.size());

        int mx(0), s(0);
        for (int n : arr) {
            mx = max(mx, n);
            s += n;
        }
        if (s <= target) { return mx; }

        sort(arr.begin(), arr.end());
        vector<int> sums(arr);
        for (int i(1); i < n; ++i) { sums[i] += sums[i - 1]; }

        int left(0), right(mx), mid(0);
        int now(0);
        while (left < right) {
            mid = left + ((right - left) >> 1);
            now = calNewSum(arr, sums, mid);
            //cout << left << ' ' << right << ' ' << mid << ' ' << now << endl;

            if (now == target) {
                return mid;
            } else if (now > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //cout << left << '-' << calNewSum(arr, sums, left - 1) << '-' << calNewSum(arr, sums, left) << endl;

        return abs(calNewSum(arr, sums, left - 1) - target) <= abs(calNewSum(arr, sums, left) - target) ? left - 1 : left;
    }
private:
    int calNewSum(const vector<int>& arr, const vector<int>& sums, const int val) {
        auto bound = upper_bound(arr.begin(), arr.end(), val);
        if (bound == arr.begin()) { return val * arr.size(); }
        return sums[bound - arr.begin() - 1] + (arr.end() - bound) * val;
    }
};
// @lc code=end

