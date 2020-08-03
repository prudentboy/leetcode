/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if (min(mountainArr.get(0), mountainArr.get(mountainArr.length() - 1)) > target) { return -1; }

        int left(0), mid(0), right(mountainArr.length() - 1);
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid == 0) {
                left = 1;
            } else if (mountainArr.get(mid) < mountainArr.get(mid - 1)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int peak(left - 1);

        if (mountainArr.get(peak) < target) { return -1; }
        // left part
        left = 0;
        right = peak;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) == target) { return mid; }
            if (mountainArr.get(mid) > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // right part
        left = peak;
        right = mountainArr.length() - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            cout << left << ' ' << mid << ' ' << right << endl;
            if (mountainArr.get(mid) == target) { return mid; }
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

