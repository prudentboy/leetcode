/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        array<int, 2> v({INT_MAX, INT_MAX});

        for (int n : nums)
        {
            if (n <= v[0]) v[0] = n;
            else if (n <= v[1]) v[1] = n;
            else return true;
        }

        return false;
    }
};

