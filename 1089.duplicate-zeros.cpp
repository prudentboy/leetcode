/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt(0), len(arr.size());
        for (int n : arr)
        {
            if (n == 0) ++cnt;
        }
        if (cnt == 0) return;

        arr.reserve(arr.size() + cnt);
        vector<int> tmp(cnt, 0);
        arr.insert(arr.end(), tmp.begin(), tmp.end());

        for (int i = len + cnt - 1, j = len - 1; j >= 0; --j)
        {
            if (arr[j] == 0) arr[i--] = 0;
            arr[i--] = arr[j];
        }
        arr.resize(len);
    }
};

