/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 */

// @lc code=start
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        /*
        int n(arr.size()), left(-1), right(-1);

        auto findMin = [&]() -> int {
            int mn(INT_MAX);
            int i(0), j(0), sum(0);
            for (i = 0; i < n; ++i) {
                sum += arr[i];
                while (sum > target) { sum -= arr[j++]; }
                if (sum == target) {
                    if (left != -1 && !(left > i || j > right)) { continue; }
                    if (i - j + 1 < mn) {
                        mn = i - j + 1;
                        left = j;
                        right = i;
                    }
                }
            }
            return mn;
        };

        int mn1(findMin());
        if (mn1 == INT_MAX) { return -1; }
        cout << mn1 << ' ' << left << ' ' << right << endl;
        int mn2(findMin());
        if (mn2 == INT_MAX) { return -1; }
        cout << mn2 << ' ' << left << ' ' << right << endl;
        return mn1 + mn2;
        */
        int n(arr.size());
        int ans(1000000);
        int i(0), j(0), sum(0), len(INT_MAX);
        vector<int> mns(n, 1000000);
        for (i = 0; i < n; ++i) {
            sum += arr[i];
            while (sum > target) { sum -= arr[j++]; }
            if (sum == target) {
                if (j > 0) { ans = min(ans, mns[j - 1] + i - j + 1); }
                len = min(len, i - j + 1);
            }
            mns[i] = min(mns[i], len);
        }
        return ans > 100001 ? -1 : ans;
    }
};
// @lc code=end

