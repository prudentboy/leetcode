/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans(3, 0);

        int n(nums.size());
        vector<int> sum(nums);
        int i(0);
        for (i = 1; i < n; ++i) { sum[i] += sum[i - 1]; }
        /*
        cout << "sum : " << endl;
        for (i = 0; i < n; ++i) { cout << sum[i] << ' '; }
        cout << endl;
        */

        int tmp(0);
        int mx(0), idx(0);
        vector<int> left(n, 0);
        for (i = 0; i + k - 1 < n; ++i) {
            tmp = getSum(sum, i, k);
            if (tmp > mx) {
                mx = tmp;
                idx = i;
            }
            left[i] = idx;
        }
        /*
        cout << "left : " << endl;
        for (i = 0; i < n; ++i) { cout << left[i] << ' '; }
        cout << endl;
        */

        vector<int> right(n, 0);
        mx = 0;
        for (i = n - k; i >= 0; --i) {
            tmp = getSum(sum, i, k);
            if (tmp >= mx) {
                mx = tmp;
                idx = i;
            }
            right[i] = idx;
        }
        /*
        cout << "right : " << endl;
        for (i = 0; i < n; ++i) { cout << right[i] << ' '; }
        cout << endl;
        */

        mx = 0;
        for (i = k; i + k + k <= n; ++i) {
            tmp = getSum(sum, left[i - k], k) + getSum(sum, i, k) + getSum(sum, right[i + k], k);
            if (mx < tmp) {
                mx = tmp;
                ans = {left[i - k], i, right[i + k]};
            }
        }

        return ans;
    }
private:
    int getSum(const vector<int>& sums, const int beg, const int len) {
        int big(sums[beg + len - 1]);
        int small(beg == 0 ? 0 : sums[beg - 1]);

        return big - small;
    }
};
// @lc code=end

