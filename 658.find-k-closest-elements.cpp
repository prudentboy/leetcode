/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n(arr.size());
        if (x <= arr[0]) return vector<int>(arr.begin(), arr.begin() + k);
        if (x >= arr[n - 1]) return vector<int>(arr.end() - k, arr.end());

        int l(0), r(n - 1), mid(0);
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            if (arr[mid] == x) break;
            if (arr[mid] > x) r = mid - 1;
            else l = mid + 1;
        }
        //cout << mid << endl;

        int i(0), j(0);
        if (arr[mid] == x) i = j = mid;
        else if (arr[mid] < x)
        {
            if (arr[mid + 1] - x < x - arr[mid]) ++mid;
            i = j = mid;
        }
        else
        {
            if (arr[mid] - x > x - arr[mid - 1]) --mid;
            i = j = mid;
        }
        //cout << i << ' ' << j << endl;
        if (k == 1) return vector<int>(arr[i]);

        while (--k > 0)
        {
            if (i == 0) ++j;
            else if (j == n - 1) --i;
            else if (abs(arr[j + 1] - x) < abs(arr[i - 1] - x)) ++j;
            else --i;
            //cout << i << ' ' << j << ' ' << k << endl;
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};
// @lc code=end

